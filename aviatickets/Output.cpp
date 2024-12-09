
#include "Output.h"
using namespace std;


void OutputAdmin::printTicket()
{
    sql::Connection* con;
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;

    con = connectionDB();

    pstmt = con->prepareStatement("SELECT * FROM ticketsTable");
    result = pstmt->executeQuery();

    size_t amountTickets = result->rowsCount();
    
    cout << "amount of tickets: " << amountTickets << endl;

    if (amountTickets != 0) //проверка на наличие строк в базе
    {
        cout << "\nList all tickets\n\n";
        cout << "Id\tDestination\tFlight number\tFull name\tDeparture date\tUser_id\n";

        while (result->next())
        {
            cout << result->getInt(1) << "\t" << result->getString(2) << "\t\t" << result->getInt(3) << "\t\t" << result->getString(4) << "\t\t" << result->getString(5) <<"\t"<<result->getInt(6)<< endl;
        }
    }

    delete con;
    delete pstmt;
    delete result;
}

void OutputAdmin::printTicketbyNo(int ticket_id)
{
    sql::Connection* con;
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;

    con = connectionDB();
    pstmt = con->prepareStatement("SELECT * FROM ticketsTable WHERE id_ticket = ?");
    pstmt->setInt(1, ticket_id);
    result = pstmt->executeQuery();

    result->next();
    cout << "Id\tDestination\tFlight number\tFull name\tDeparture date\tUser_id\n";
    cout << result->getInt(1) << "\t" << result->getString(2) << "\t\t" << result->getInt(3) << "\t\t" << result->getString(4) << "\t\t" << result->getString(5) << "\t" << result->getInt(6) << endl;

    delete con;
    delete pstmt;
    delete result;
}


void OutputUser::printTicketUser(int user_id) 
{
    sql::Connection* con;
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;

    con = connectionDB();
    pstmt = con->prepareStatement("SELECT * FROM ticketsTable WHERE user_id = ?");
    pstmt->setInt(1, user_id);
    result = pstmt->executeQuery();

    size_t amountTickets = result->rowsCount();

    cout << "amount of tickets: " << amountTickets << endl;

    if (amountTickets != 0) //проверка на наличие строк в базе
    {
        cout << "\nlist of tickets user \n\n";
        cout << "Id\tDestination\tFlight number\tFull name\tDeparture date\n";

        while (result->next())
        {
            cout << result->getInt(1) << "\t" << result->getString(2) << "\t\t" << result->getInt(3) << "\t\t" << result->getString(4) << "\t\t" << result->getString(5) << "\t" << endl;
        }
    }

    delete con;
    delete pstmt;
    delete result;
}