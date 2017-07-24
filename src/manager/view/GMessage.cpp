#include "GMessage.h"
#include "ui_GMessage.h"
#include "GPicto.h"
#include <QTimer>

GMessage::GMessage(QWidget* parent) :
    QFrame(parent), ui(new Ui::GMessage) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
}

GMessage::~GMessage() {
    delete ui;
}

void GMessage::createObjects() {
    ui->m_iconLayout->setAlignment(Qt::AlignTop);
    ui->m_close->setIcon(GPicto::Instance()->getPicto(fa::times, "white"));
    ui->m_closeLayout->setAlignment(Qt::AlignTop);
    setVisible(false);
}

void GMessage::createConnexions() {
    connect(ui->m_close, SIGNAL(clicked()), this, SLOT(hide()));
}

void GMessage::showMessage(const QString& message) {
    setVisible(true);
    ui->m_icon->setIcon(GPicto::Instance()->getPicto(fa::checkcircle, "#89a830"));
    ui->m_message->setStyleSheet("QLabel{color:#89a830}");
    ui->m_message->setText(message);
}

void GMessage::showMessage(const QString& message, const int& msec) {
    setVisible(true);
    ui->m_icon->setIcon(GPicto::Instance()->getPicto(fa::checkcircle, "#89a830"));
    ui->m_message->setStyleSheet("QLabel{color:#89a830}");
    ui->m_message->setText(message);
    QTimer::singleShot(msec, this, SLOT(hide()));
}

void GMessage::showError(const QString& message) {
    setVisible(true);
    ui->m_icon->setIcon(GPicto::Instance()->getPicto(fa::exclamationtriangle, "#f67b20"));
    ui->m_message->setStyleSheet("QLabel{color:#f67b20}");
    ui->m_message->setText(message);
}

void GMessage::showError(const QString& message, const int& msec) {
    setVisible(true);
    ui->m_icon->setIcon(GPicto::Instance()->getPicto(fa::exclamationtriangle, "#f67b20"));
    ui->m_message->setStyleSheet("QLabel{color:#f67b20}");
    ui->m_message->setText(message);
    QTimer::singleShot(msec, this, SLOT(hide()));
}
