
#ifndef LOGIN_H
#define LOGIN_H

#include "ConnectionDB.h"

#include <cppconn/prepared_statement.h>

#include <iostream>

//int login();
int loginUser();
void loginAdmin();

int getUserId(std::string pasUser);
#endif

