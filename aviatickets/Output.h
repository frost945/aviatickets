//#pragma once

#ifndef OUTPUT_H
#define OUTPUT_H

#include "ArrayTickets.h"

class OutputAdmin 
{
public:
    void readTickets();
    void readTicketbyNo(int ticketId);
};

class OutputUser 
{
public:
    void readTickets(int userId);
};

#endif
