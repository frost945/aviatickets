#include "ArrayTickets.h"

  std::vector<Ticket> ArrayTickets::arrayTickets;
  int ArrayTickets::lastTicketId = 0;

int ArrayTickets::getLastTicketId()
{
	Ticket t;
	
	t = arrayTickets.back();
	
	return t.getTicketId();
}
void ArrayTickets::addTicket(Ticket& ticket)
{
	arrayTickets.push_back(ticket);
}

void ArrayTickets::deleteTicket(int ticketId)
{
	for (int i = 0; i < arrayTickets.size(); ++i)
		if (arrayTickets.at(i).getTicketId() == ticketId)
		{
			arrayTickets.erase(arrayTickets.begin() + i); break;
		}
}
