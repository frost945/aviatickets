
#include "Control.h"

using namespace std;

bool Control::checkRows()
{
    sql::Connection* con;
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;

    con = connectionDB();
    pstmt = con->prepareStatement("SELECT EXISTS(SELECT id_ticket FROM ticketsTable WHERE id_ticket = 1)");
    result = pstmt->executeQuery();

    result->next();
    bool n;
    n = result->getBoolean(1);
   // cout <<"checkRows: " << n << endl;

    delete con;
    delete pstmt;
    delete result;

    return n;
}


void Control::creatTicket(int userId)
{
    sql::Connection* con;
    sql::PreparedStatement* pstmt;

    con = connectionDB();
    pstmt=con->prepareStatement("INSERT INTO ticketsTable (destination, flight_number, full_name, departure_date, user_id) VALUES(?,?,?,?,?)");

    cout << "write destination  ";
    string destination;
    cin >> destination; cout << "\n";
    pstmt->setString(1, destination);

    cout << "write flightNumber  ";
    int flightNumber;
    cin >> flightNumber; cout << "\n";
    pstmt->setInt(2, flightNumber);

    cout << "write full Name  ";
    string fullName;
    cin >> fullName; cout << "\n";
    pstmt->setString(3, fullName);

    cout << "write departure Date  ";
    string departureDate;
    cin >> departureDate; cout << "\n";
    pstmt->setString(4, departureDate);

    pstmt->setInt(5, userId);
    pstmt->executeQuery();

    cout << "ticket successfully created!\n\n";

    delete con;
    delete pstmt;
}

void Control::deleteTicket()
{
    sql::Connection* con;
    sql::PreparedStatement* pstmt;

    if (checkRows()==0 )
    {
        cout << "no tickets\n"; return;
    }

        OutputAdmin output;
        output.printTicket();
        cout << "\nselect ticket to delete ";
        int id;
        cin >> id;

        if (id>0)
        {
            con = connectionDB();
            pstmt = con->prepareStatement("DELETE FROM ticketsTable WHERE id_ticket = ?");
            pstmt->setInt(1, id);
            pstmt->executeUpdate();
            cout << "\nticket number " << id << " deleted\n";

            delete con;
            delete pstmt;
        }
}

 int Control::updateTicket()
{
    if (checkRows() == 0)
    { cout << "no tickets\n"; return 0;}

    OutputAdmin outputAdmin;
    outputAdmin.printTicket();

    cout << "\nselect ticket for redaction ";
    int id;
    cin >> id;

    sql::Connection* con;
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;

    while (true)//цикл для продолжения редактирования параметров билета
    {
        /*/con = connectionDB();
        pstmt = con->prepareStatement("SELECT * FROM ticketsTable WHERE id_ticket = ?");
        pstmt->setInt(1, id);
        result = pstmt->executeQuery();

       // result->last();// ставим курсор в конец выбранной строки
        result->next();
        cout << "Id\tDestination\tFlight number\tFull name\tDeparture date\n";
        cout << result->getInt(1) << "\t" << result->getString(2) << "\t\t" << result->getInt(3) << "\t\t" << result->getString(4) << "\t\t" << result->getString(5) << endl;*/

        OutputAdmin outputAdmin;
        outputAdmin.printTicketbyNo(id);

        cout << "\nselect parameter for redaction\n";
        cout << "1-destination, 2-flight number, 3-full name, 4-departure date\n";

        int column;
        cin >> column; //выбираем нужный столбец для редактирования

        switch (column)
        {
        case 1: updateDestination(id); break;
        case 2: updateFlightNumber(id); break;
        case 3: updateFullName(id); break;
        case 4: updateDepartureDate(id); break;
        }
        cout << "press any key to continue, to exit press 'n': ";
        char ch;
        cin >> ch;
        if (ch == 'n') break;
    }
        return id;
}

void Control::updateDestination(int id)
{
    cout << "enter new destination: ";
    string newDest;
    cin >> newDest;

    sql::Connection* con;
    sql::PreparedStatement* pstmt;

    con = connectionDB();
    pstmt = con->prepareStatement("UPDATE ticketsTable SET destination = ? WHERE id_ticket = ?");
    pstmt->setString(1, newDest);
    pstmt->setInt(2, id);
    pstmt->executeQuery();
    
    cout << "destination successfully changed to: " << newDest << "\n";

    delete con;
    delete pstmt;
}

void Control::updateFlightNumber(int id)
{
    cout << "enter new flight number: ";
    int newflight;
    cin >> newflight;

    sql::Connection* con;
    sql::PreparedStatement* pstmt;

    con = connectionDB();
    pstmt = con->prepareStatement("UPDATE ticketsTable SET flight_number = ? WHERE id_ticket = ?");
    pstmt->setInt(1, newflight);
    pstmt->setInt(2, id);
    pstmt->executeQuery();

    cout << "flight number successfully changed to: " << newflight << "\n";

    delete con;
    delete pstmt;
}

void Control::updateFullName(int id)
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
}

void Control::updateDepartureDate(int id)
{
    cout << "enter new departure date: ";
    string newdate;
    cin >> newdate;

    sql::Connection* con;
    sql::PreparedStatement* pstmt;

    con = connectionDB();
    pstmt = con->prepareStatement("UPDATE ticketsTable SET departure_date = ? WHERE id_ticket = ?");
    pstmt->setString(1, newdate);
    pstmt->setInt(2, id);
    pstmt->executeQuery();

    cout << "departure date successfully changed to: " << newdate << "\n";

    delete con;
    delete pstmt;
}
