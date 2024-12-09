//#pragma once

#ifndef OUTPUT_H
#define OUTPUT_H


#include "ConnectionDB.h"

#include "mysql_connection.h"
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

#include <iostream>
/*
class Output
{
protected:
    Output() {};
public:
};*/

class OutputAdmin
{
public:
     void  printTicket();
     void printTicketbyNo(int ticket_id);
};

class OutputUser
{
public:
     void  printTicketUser(int user_id);

};

#endif
