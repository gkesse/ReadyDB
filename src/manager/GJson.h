#ifndef _GJson_
#define _GJson_

#include "GTypeDef.h"
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>

class GJson : public QObject {
    Q_OBJECT

private:
    GJson();

public:
    ~GJson();

public:
    static GJson* Instance();

private:
    void createObjects();
    void createConnexions();

public:
    void load(const QString& filename, QIODevice::OpenMode mode = QIODevice::ReadOnly);
    void save(const QString& filename = "", const QJsonDocument::JsonFormat& format = QJsonDocument::Indented);
    void setValue(const QString& key, const QVariant& data);
    void addArray(const QString& key, const QVariantMap& data);
    QString getValue(const QString& key);
    GArrayMap getArray(const QString& key);
    QStringList getArray(const QString& key1, const QString& key2);

private:
    static GJson* m_instance;
    QJsonObject m_jsonObj;
    QString m_filename;
};

#endif
