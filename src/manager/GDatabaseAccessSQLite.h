#ifndef _GDatabaseAccessSQLite_
#define _GDatabaseAccessSQLite_

#include "GDatabaseAccess.h"

class GDatabaseAccessSQLite : public GDatabaseAccess {
private:
    GDatabaseAccessSQLite();

public:
    ~GDatabaseAccessSQLite();

public:
    static GDatabaseAccessSQLite* Instance();
    
private:
    void createObjects();
    void createConnexions();

public:
    bool openDatabase();
    void createDatabase();

private:
    static GDatabaseAccessSQLite* m_instance;
};

#endif
