#include "GDatabaseAccess.h"
#include "GDatabaseAccessSQLite.h"
#include "GDatabaseAccessMySQL.h"
#include "GConfig.h"
#include <QSqlDatabase>

GDatabaseAccess::GDatabaseAccess() {

}

GDatabaseAccess::~GDatabaseAccess() {
    
}

GDatabaseAccess* GDatabaseAccess::Instance() {
    int m_dbms = GConfig::Instance()->getData("DBMS").toInt();

    if(m_dbms == GConfig::SQLITE) {
        return GDatabaseAccessSQLite::Instance();
    }
    else if(m_dbms == GConfig::MYSQL) {
        return GDatabaseAccessMySQL::Instance();
    }

    return 0;
}

void GDatabaseAccess::setName(const QString& name) {
    m_name = name;
}

void GDatabaseAccess::setConnection(const QString& conn) {
    m_conn = conn;
}

QStringList GDatabaseAccess::getDrivers() const {
    QStringList m_drivers = QSqlDatabase::drivers();
    return m_drivers;
}
