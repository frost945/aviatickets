
#include "Output.h"

using std::cout; using std::endl;

void OutputAdmin::readTickets()
{
    if (ArrayTickets::arrayTickets.size() == 0) {cout << "amount of tickets: 0" << endl; return;}

    cout << "\nList all tickets\n\n";
    cout << "Ticket_Id\tDestination\tFlight number\tDeparture date\tUser_id\n";

    for (auto& t : ArrayTickets::arrayTickets)
        cout << t.getTicketId() << "\t\t" << t.getDestination() << "\t\t" << t.getFlightNo() << "\t\t" << t.getDepartDate() << "\t" << t.getUserId() << endl;

}

void OutputAdmin::readTicketbyNo(int ticketId)
{
    cout << "Ticket_Id\tDestination\tFlight number\tDeparture date\tUser_id\n";

    for (auto& t : ArrayTickets::arrayTickets)
        if (t.getTicketId() == ticketId)
            cout << t.getTicketId() << "\t\t" << t.getDestination() << "\t\t" << t.getFlightNo() << "\t\t" << t.getDepartDate() << "\t" << t.getUserId() << endl;


}

void OutputUser::readTickets(int userId)
{
    int count=0;
    for (auto& t : ArrayTickets::arrayTickets)
        if (t.getUserId() == userId) {++count; break;}

    if (count == 0) { cout << "amount of tickets: 0" << endl; return; }

    cout << "\nlist of tickets user \n\n";
    cout << "Ticket_Id\tDestination\tFlight number\tDeparture date\n";

    for ( auto& t : ArrayTickets::arrayTickets)
        if(t.getUserId() == userId)
            cout << t.getTicketId() << "\t\t" << t.getDestination() << "\t\t" << t.getFlightNo() << "\t\t" << t.getDepartDate() << endl;

}