#include "GDatabaseAccessSQLite.h"
#include <QSqlDatabase>

#include "GMessageView.h"

GDatabaseAccessSQLite* GDatabaseAccessSQLite::m_instance = 0;

GDatabaseAccessSQLite::GDatabaseAccessSQLite() {
    createObjects();
    createConnexions();
}

GDatabaseAccessSQLite::~GDatabaseAccessSQLite() {
    
}

GDatabaseAccessSQLite* GDatabaseAccessSQLite::Instance() {
    if(m_instance == 0) {
        m_instance = new GDatabaseAccessSQLite;
    }
    
    return m_instance;
}

void GDatabaseAccessSQLite::createObjects() {

}

void GDatabaseAccessSQLite::createConnexions() {
    
}

bool GDatabaseAccessSQLite::openDatabase() {
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE", m_conn);
    m_db.setDatabaseName(m_name);
    bool m_open = m_db.open();
    return m_open;
}

void GDatabaseAccessSQLite::createDatabase() {

}

