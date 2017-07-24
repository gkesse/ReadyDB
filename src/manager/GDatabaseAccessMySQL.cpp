#include "GDatabaseAccessMySQL.h"
#include <QSqlDatabase>

#include "GMessageView.h"

GDatabaseAccessMySQL* GDatabaseAccessMySQL::m_instance = 0;

GDatabaseAccessMySQL::GDatabaseAccessMySQL() {
    createObjects();
    createConnexions();
}

GDatabaseAccessMySQL::~GDatabaseAccessMySQL() {
    
}

GDatabaseAccessMySQL* GDatabaseAccessMySQL::Instance() {
    if(m_instance == 0) {
        m_instance = new GDatabaseAccessMySQL;
    }
    
    return m_instance;
}

void GDatabaseAccessMySQL::createObjects() {

}

void GDatabaseAccessMySQL::createConnexions() {
    
}

bool GDatabaseAccessMySQL::openDatabase() {
    return 0;
}

void GDatabaseAccessMySQL::createDatabase() {
    GMessageView::Instance()->showData("GDatabaseAccessMySQL createDatabase");
}

