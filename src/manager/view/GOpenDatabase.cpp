#include "GOpenDatabase.h"
#include "ui_GOpenDatabase.h"
#include "GSplashScreen.h"
#include "GPicto.h"
#include "GDatabaseAccess.h"
#include "GGlobal.h"
#include "GJson.h"
#include "GConfig.h"

GOpenDatabase::GOpenDatabase(QWidget* parent) :
    QFrame(parent), ui(new Ui::GOpenDatabase) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GOpenDatabase : loading GOpenDatabase module...");
}

GOpenDatabase::~GOpenDatabase() {
    delete ui;
}

void GOpenDatabase::createObjects() {
    GArrayMap m_arrayMap;
    GJson::Instance()->load(":/json/OpenDatabase.json");

    ui->m_title->setIcon(GPicto::Instance()->getPicto(fa::book));
    ui->m_nameIcon->setIcon(GPicto::Instance()->getPicto(fa::filetext));
    ui->m_hostnameIcon->setIcon(GPicto::Instance()->getPicto(fa::filetext));
    ui->m_portIcon->setIcon(GPicto::Instance()->getPicto(fa::filetext));
    ui->m_usernameIcon->setIcon(GPicto::Instance()->getPicto(fa::filetext));
    ui->m_passwordIcon->setIcon(GPicto::Instance()->getPicto(fa::filetext));
    ui->m_open->setIcon(GPicto::Instance()->getPicto(fa::check));
    ui->m_buttonLayout->setAlignment(Qt::AlignCenter);

    m_arrayMap = GJson::Instance()->getArray("drivers");
    QStringList m_drivers = GGlobal::Instance()->getList(m_arrayMap, "name");
    ui->m_dbms->addItems(m_drivers);
    ui->m_dbms->setCurrentText("SQLITE");
    slotDbmsChanged("SQLITE");
}

void GOpenDatabase::createConnexions() {
    connect(ui->m_dbms, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotDbmsChanged(QString)));
    connect(ui->m_open, SIGNAL(clicked()), this, SLOT(slotOpenDatabase()));
}

void GOpenDatabase::setFieldVisible(const bool& data) {
    ui->m_nameWidget->setVisible(data);
    ui->m_hostnameWidget->setVisible(data);
    ui->m_portWidget->setVisible(data);
    ui->m_usernameWidget->setVisible(data);
    ui->m_passwordWidget->setVisible(data);
}

void GOpenDatabase::slotDbmsChanged(const QString& data) {
    if(data == "SQLITE") {
        setFieldVisible(false);
        ui->m_nameWidget->setVisible(true);
        GConfig::Instance()->setData("DBMS", GConfig::SQLITE);
    }
    else if(data == "MYSQL"){
        setFieldVisible(true);
        ui->m_nameWidget->setVisible(false);
        GConfig::Instance()->setData("DBMS", GConfig::MYSQL);
    }
}


void GOpenDatabase::slotOpenDatabase() {
    bool m_validate = true;

    if(ui->m_nameWidget->isVisible() == true) {
        if(ui->m_name->text().isEmpty() == true) {
            m_validate = false;
        }
    }
    if(ui->m_hostnameWidget->isVisible() == true) {
        if(ui->m_hostname->text().isEmpty() == true) {
            m_validate = false;
        }
    }
    if(ui->m_portWidget->isVisible() == true) {
        if(ui->m_port->text().isEmpty() == true) {
            m_validate = false;
        }
    }
    if(ui->m_usernameWidget->isVisible() == true) {
        if(ui->m_username->text().isEmpty() == true) {
            m_validate = false;
        }
    }
    if(ui->m_passwordWidget->isVisible() == true) {
        if(ui->m_password->text().isEmpty() == true) {
            m_validate = false;
        }
    }
    if(m_validate == false) {
        ui->m_message->showError("ERROR : You must fill in all fields.");
        return;
    }
    if(ui->m_dbms->currentText() == "SQLITE") {
        GDatabaseAccess::Instance()->setName(ui->m_name->text());
        GDatabaseAccess::Instance()->setConnection("conn1");
        GJson::Instance()->addArray("names", ui->m_name->text());
        bool m_open = false;
        //m_open = GDatabaseAccess::Instance()->openDatabase();
        if(m_open == false) {
            ui->m_message->showError("ERROR : The operation failed.");
        }
        else {
            ui->m_message->showMessage("SUCCESS : The operation was successful.");
        }
        return;
    }
}
