

#ifndef CONNECTIONDB_H
#define CONNECTIONDB_H

#include <iostream>

#include "PasswordDB.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>

sql::Connection* connectionDB();
#endif