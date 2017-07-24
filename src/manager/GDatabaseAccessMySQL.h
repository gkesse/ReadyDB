#ifndef _GDatabaseAccessMySQL_
#define _GDatabaseAccessMySQL_

#include "GDatabaseAccess.h"

class GDatabaseAccessMySQL : public GDatabaseAccess {
private:
    GDatabaseAccessMySQL();

public:
    ~GDatabaseAccessMySQL();

public:
    static GDatabaseAccessMySQL* Instance();
    
private:
    void createObjects();
    void createConnexions();
    
public:
    bool openDatabase();
    void createDatabase();

private:
    static GDatabaseAccessMySQL* m_instance;
};

#endif
