#include "GJson.h"

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

void GJson::load(const QString& filename, QIODevice::OpenMode mode) {
    m_filename = filename;
    QFile m_file(m_filename);
    mode = mode | QIODevice::Text;
    m_file.open(mode);
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

void GJson::setValue(const QString& key, const QVariant& data) {
    m_jsonObj.insert(key, data.toString());
    save();
}

void GJson::addArray(const QString& key, const QVariantMap& data) {
    QJsonArray m_array = m_jsonObj.value(key).toArray();
    QJsonObject m_object;

    for(int i = 0; i < data.size(); i++) {
        QString m_key = data.keys().at(i);
        QString m_value = data.value(m_key).toString();
        m_object.insert(m_key, m_value);
    }

    m_array.push_back(m_object);
    m_jsonObj.insert(key, m_array);
    save();
}

QString GJson::getValue(const QString& key) {
    QString m_data = m_jsonObj.value(key).toString();
    return m_data;
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

QStringList GJson::getArray(const QString& key1, const QString& key2) {
    QJsonArray m_array = m_jsonObj.value(key1).toArray();
    int m_size = m_array.size();
    QStringList m_dataMap;

    for(int i = 0; i < m_size; i++) {
        QJsonObject m_object = m_array.at(i).toObject();
        QString m_data = m_object.value(key2).toString();
        m_dataMap.push_back(m_data);
    }

    return m_dataMap;
}
