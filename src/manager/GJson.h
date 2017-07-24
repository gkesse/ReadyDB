#ifndef _GJson_
#define _GJson_

#include "GTypeDef.h"
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

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
    void load(const QString& filename);
    void save(const QString& filename = "", const QJsonDocument::JsonFormat& format = QJsonDocument::Indented);
    void addArray(const QString& key, const QVariant& data);
    GArrayMap getArray(const QString& key);

private:
    static GJson* m_instance;
    QJsonObject m_jsonObj;
    QString m_filename;
};

#endif
