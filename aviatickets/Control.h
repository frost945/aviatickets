
#ifndef CONTROL_H
#define CONTROL_H

#include "Output.h"
#include "ManagementDB.h"

class ControlUser
{
private:

public:
    void creatTicket(int userId);
    void deleteTicket();
    void updateTicket();

    void updateDestination(int ticketId);
    void updateFlightNo(int ticketId);
    void updateDepartureDate(int ticketId);
    // void updateFullName(int ticketId);
};

class ControlAdmin:public ControlUser
{
public:
    void creatTicket();
};

#endif
