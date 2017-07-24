#include "GGlobal.h"
#include "GPicto.h"

GGlobal* GGlobal::m_instance = 0;

GGlobal::GGlobal() {
    createObjects();
    createConnexions();
}

GGlobal::~GGlobal() {

}

GGlobal* GGlobal::Instance() {
    if(m_instance == 0) {
        m_instance = new GGlobal;
    }

    return m_instance;
}

void GGlobal::createObjects() {

}

void GGlobal::createConnexions() {

}

void GGlobal::hide(QWidget* widget) {
    widget->hide();
}

void GGlobal::setVisible(QFormLayout* form, QWidget* field, const bool& data) {
    QWidget* m_label = form->labelForField(field);
    m_label->setVisible(data);
    field->setVisible(data);
}

void GGlobal::showMessage(QWidget* widget, QToolButton* icon, QLabel* label, const QString& message) {
    if(widget != 0) widget->setVisible(true);
    if(icon != 0) icon->setIcon(GPicto::Instance()->getPicto(fa::checkcircle, "#89a830"));
    if(icon != 0) icon->setIconSize(QSize(18, 18));
    label->setStyleSheet("QLabel{color:#89a830}");
    label->setText(message);
}

void GGlobal::showError(QWidget* widget, QToolButton* icon, QLabel* label, const QString& message) {
    if(widget != 0) widget->setVisible(true);
    if(icon != 0) icon->setIcon(GPicto::Instance()->getPicto(fa::exclamationtriangle, "#f67b20"));
    if(icon != 0) icon->setIconSize(QSize(18, 18));
    label->setStyleSheet("QLabel{color:#f67b20}");
    label->setText(message);
}

QStringList GGlobal::getList(const GArrayMap& data, const QString& key) {
    QStringList m_datas;
    for(int i = 0; i < data.size(); i++) {
        QVariantMap m_dataMap = data.at(i);
        QString m_data = m_dataMap.value(key).toString();
        m_datas.push_back(m_data);
    }
    return m_datas;
}
