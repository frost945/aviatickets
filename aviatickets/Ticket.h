#pragma once
#include <iostream>

class Ticket
{
private:
	int m_ticketId;
	std::string m_destination;
	int m_flightNo;
	std::string m_departDate;
	int m_userId;

public:
	 int getTicketId() const { return m_ticketId; }
	 std::string getDestination() const { return m_destination; }
	 int getFlightNo() const { return m_flightNo; }
	 std::string getDepartDate() const { return m_departDate; }
	 int getUserId() const { return m_userId; }

	void setTicketId(int ticketId) { m_ticketId = ticketId; }
	void setDestination(std::string dest) { m_destination = dest; }
	void setFlightNo(int flightNo) { m_flightNo = flightNo; }
	void setDepartDate(std::string departDate) { m_departDate = departDate; }
	void setUserId(int userId) { m_userId = userId; }
};

