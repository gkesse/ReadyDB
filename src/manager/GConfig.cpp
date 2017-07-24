#include "GConfig.h"

GConfig* GConfig::m_instance = 0;

GConfig::GConfig() {
    createObjects();
    createConnexions();
}

GConfig::~GConfig() {

}

GConfig* GConfig::Instance() {
    if(m_instance == 0) {
        m_instance = new GConfig;
    }

    return m_instance;
}

void GConfig::createObjects() {
    setData("DBMS", GConfig::SQLITE);
}

void GConfig::createConnexions() {

}

void GConfig::setData(const QString& key, const QVariant& value) {
    m_dataMap.insert(key, value);
}

QVariant GConfig::getData(const QString& key) {
    return m_dataMap.value(key);
}
