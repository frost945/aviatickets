//#pragma once

#ifndef CONTROL_H
#define CONTROL_H

#include "mysql_connection.h"
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

#include "Output.h"
#include "ConnectionDB.h"

#include <iostream>
#include <cstring>

class Control
{
public:
    Control() {};

    bool checkRows();

    void creatTicket(int userId);
    void deleteTicket();
    int updateTicket();

    void updateDestination(int id);
    void updateFlightNumber(int id);
    void updateFullName(int id);
    void updateDepartureDate(int id);
};

#endif
