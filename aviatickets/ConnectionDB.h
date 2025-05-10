

#ifndef CONNECTIONDB_H
#define CONNECTIONDB_H

#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>

#include "PasswordDB.h"

class ConnectionDB
{
private:
	static sql::Connection* connectionDB();

public:
	static sql::Connection* con;
};

#endif