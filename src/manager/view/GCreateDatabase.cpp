#include "GCreateDatabase.h"
#include "ui_GCreateDatabase.h"
#include "GSplashScreen.h"
#include "GPicto.h"
#include "GDatabaseAccess.h"

GCreateDatabase::GCreateDatabase(QWidget* parent) :
    QFrame(parent), ui(new Ui::GCreateDatabase) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GCreateDatabase : loading GCreateDatabase module...");
}

GCreateDatabase::~GCreateDatabase() {
    delete ui;
}

void GCreateDatabase::createObjects() {
    ui->m_title->setIcon(GPicto::Instance()->getPicto(fa::book));
    ui->m_create->setIcon(GPicto::Instance()->getPicto(fa::check));
}

void GCreateDatabase::createConnexions() {
    connect(ui->m_create, SIGNAL(clicked()), this, SLOT(slotCreateDatabse()));
}

void GCreateDatabase::slotCreateDatabse() {
    GDatabaseAccess::Instance()->createDatabase();
}
