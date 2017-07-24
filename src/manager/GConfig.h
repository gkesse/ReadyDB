#ifndef _GConfig_
#define _GConfig_

#include <QObject>
#include <QVariantMap>

class GConfig : public QObject {
    Q_OBJECT

public:
    enum DBMS {SQLITE, MYSQL};
    Q_ENUM(DBMS)

private:
    GConfig();

public:
    ~GConfig();

public:
    static GConfig* Instance();

private:
    void createObjects();
    void createConnexions();

public:
    void setData(const QString& key, const QVariant& value);
    QVariant getData(const QString& key);

private:
    static GConfig* m_instance;
    QVariantMap m_dataMap;
};

#endif
