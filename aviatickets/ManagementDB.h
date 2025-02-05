#pragma once

#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

#include "ConnectionDB.h"
#include "ArrayTickets.h"

class ManagementDB
{
private:


public:
	bool checkRows();
	std::vector<Ticket> getDataTickets();
	void addTicket(Ticket& t);
	void deleteTicket(int ticketId);
	void updateDestination(int ticketId, std::string newDest);
	void updateFlightNo(int ticketId, int newFlightNo);
	void updateDepartureDate(int ticketId, std::string newDepartDate);
	std::string getUserName(int userId);
};
