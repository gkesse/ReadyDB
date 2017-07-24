#include "GJson.h"
#include <QFile>

GJson* GJson::m_instance = 0;

GJson::GJson() {
    createObjects();
    createConnexions();
}

GJson::~GJson() {

}

GJson* GJson::Instance() {
    if(m_instance == 0) {
        m_instance = new GJson;
    }

    return m_instance;
}

void GJson::createObjects() {

}

void GJson::createConnexions() {

}

void GJson::load(const QString& filename) {
    m_filename = filename;
    QFile m_file(m_filename);
    m_file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString m_dataMap = m_file.readAll();
    m_file.close();
    m_jsonObj = QJsonDocument::fromJson(m_dataMap.toUtf8()).object();
}

void GJson::save(const QString& filename, const QJsonDocument::JsonFormat& format) {
    if(filename.isEmpty() == false) m_filename = filename;
    QFile m_file(m_filename);
    m_file.open(QIODevice::WriteOnly | QIODevice::Text);
    m_file.write(QJsonDocument(m_jsonObj).toJson(format));
    m_file.close();
}

GArrayMap GJson::getArray(const QString& key) {
    QJsonArray m_array = m_jsonObj.value(key).toArray();
    int m_size = m_array.size();
    GArrayMap m_arrayMap;

    for(int i = 0; i < m_size; i++) {
        QJsonObject m_object = m_array.at(i).toObject();
        int m_size2 = m_object.size();

        QVariantMap m_dataMap;

        for(int j = 0; j < m_size2; j++) {
            QString m_key = m_object.keys().at(j);
            QVariant m_value = m_object.value(m_key).toVariant();
            m_dataMap.insert(m_key, m_value);
        }

        m_arrayMap.push_back(m_dataMap);
    }

    return m_arrayMap;
}

void GJson::addArray(const QString& key, const QVariant& data) {
    QJsonArray m_array = m_jsonObj.value(key).toArray();
    m_array.append(data.toString());
    save();
}
