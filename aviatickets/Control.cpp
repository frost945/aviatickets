
#include "Control.h"

using std::cout; using std::cin; using std::string;


void ControlUser::creatTicket(int userId)
{
    Ticket ticket;

    int ticketId = ++ArrayTickets::lastTicketId;
    ticket.setTicketId(ticketId);

    cout << "write destination  ";
    string dest;
    cin >> dest;
    ticket.setDestination(dest); 

    cout << "write flight Number  ";
    int flightNo;
    cin >> flightNo;
    ticket.setFlightNo(flightNo);

    cout << "write departure Date  ";
    string departDate;
    cin >> departDate;
    ticket.setDepartDate(departDate);

    ticket.setUserId(userId);

    ArrayTickets::addTicket(ticket);

    ManagementDB managDB;
    managDB.addTicket(ticket);
}

void ControlUser::deleteTicket()
{
    if (ArrayTickets::arrayTickets.empty()) { cout << "no tickets\n"; return; }

    OutputAdmin outputAdmin;
    outputAdmin.readTickets();

    cout << "\nselect ticket to delete ";
    int ticketId;
    cin >> ticketId;
    
    ArrayTickets::deleteTicket(ticketId);

    ManagementDB managDB;
    managDB.deleteTicket(ticketId);
}

 void ControlUser::updateTicket()
{
    OutputAdmin outputAdmin;
    outputAdmin.readTickets();

    cout << "\nselect ticket for redaction ";
    int ticketId;
    cin >> ticketId;

    while (true)//цикл для продолжения редактирования параметров билета
    {

        OutputAdmin outputAdmin;
        outputAdmin.readTicketbyNo(ticketId);

        cout << "\nselect parameter for redaction\n";
        cout << "1-destination, 2-flight number, 3-departure date\n";

        int param;
        cin >> param; //выбираем нужный столбец для редактирования

        switch (param)
        {
        case 1: { updateDestination(ticketId); break; }
        case 2: { updateFlightNo(ticketId); break; }
        case 3: { updateDepartureDate(ticketId); break; }
        }
        cout << "press any key to continue, to exit press 'n': ";
        char ch;
        cin >> ch;
        if (ch == 'n') break;
    }
}

void ControlUser::updateDestination(int ticketId)
{
    cout << "enter new destination: ";
    string newDest;
    cin >> newDest;

    for (auto& t : ArrayTickets::arrayTickets)
        if (t.getTicketId() == ticketId)
            t.setDestination(newDest);

    ManagementDB managDB;
    managDB.updateDestination(ticketId, newDest);
}


void ControlUser::updateFlightNo(int ticketId)
{
    cout << "enter new flight number: ";
    int newflightNo;
    cin >> newflightNo;

    for (auto& t : ArrayTickets::arrayTickets)
        if (t.getTicketId() == ticketId)
            t.setFlightNo(newflightNo);
   
    ManagementDB managDB;
    managDB.updateFlightNo(ticketId, newflightNo);
}

void ControlUser::updateDepartureDate(int ticketId)
{
    cout << "enter new departure date: ";
    string newDepartDate;
    cin >> newDepartDate;

    for (auto& t : ArrayTickets::arrayTickets)
        if (t.getTicketId() == ticketId)
            t.setDepartDate(newDepartDate);

    ManagementDB managDB;
    managDB.updateDepartureDate(ticketId, newDepartDate);
}

/*void Control::updateFullName(int id)
{
    cout << "enter new full name: ";
    string newname;
    cin >> newname;

    sql::Connection* con;
    sql::PreparedStatement* pstmt;

    con = connectionDB();
    pstmt = con->prepareStatement("UPDATE ticketsTable SET full_name = ? WHERE id_ticket = ?");
    pstmt->setString(1, newname);
    pstmt->setInt(2, id);
    pstmt->executeQuery();

    cout << "full name successfully changed to: " << newname << "\n";

    delete con;
    delete pstmt;
}*/





void ControlAdmin::creatTicket()
{
    Ticket ticket;

    int ticketId = ++ArrayTickets::lastTicketId;
    ticket.setTicketId(ticketId);

    cout << "write destination  ";
    string dest;
    cin >> dest;
    ticket.setDestination(dest);

    cout << "write flight Number  ";
    int flightNo;
    cin >> flightNo;
    ticket.setFlightNo(flightNo);

    cout << "write departure Date  ";
    string departDate;
    cin >> departDate;
    ticket.setDepartDate(departDate);

    cout << "write userId: ";
    int userId;
    cin >> userId;
    ticket.setUserId(userId);

    ArrayTickets::addTicket(ticket);

    ManagementDB managDB;
    managDB.addTicket(ticket);
}