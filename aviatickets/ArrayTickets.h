#pragma once

#include <vector>

#include "Ticket.h"

class ArrayTickets
{
protected:ArrayTickets() {}

public:
	static std::vector<Ticket> arrayTickets;
	static int lastTicketId;

	static void addTicket(Ticket& ticket);
	static void deleteTicket(int ticketId);
	static int getLastTicketId();
};

