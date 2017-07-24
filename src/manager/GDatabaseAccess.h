#ifndef _GDatabaseAccess_
#define _GDatabaseAccess_

#include <QObject>

class GDatabaseAccess : public QObject {
    Q_OBJECT

public:
    GDatabaseAccess();
    virtual ~GDatabaseAccess();

public:
    static GDatabaseAccess* Instance();

public:
    void setName(const QString& name);
    void setConnection(const QString& conn);
    QStringList getDrivers() const;

public:
    virtual bool openDatabase() = 0;
    virtual void createDatabase() = 0;

protected:
    QString m_name;
    QString m_conn;
};

#endif
