#include "ManagementDB.h"


bool ManagementDB::checkRows()
{
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;

    pstmt = ConnectionDB::con->prepareStatement("SELECT EXISTS(SELECT id_ticket FROM ticketsTable WHERE id_ticket = 1)");
    result = pstmt->executeQuery();

    result->next();
    bool isRow = result->getBoolean(1);

    delete pstmt;
    delete result;

    return isRow;
}

std::vector<Ticket>  ManagementDB::getDataTickets()
{
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;

    pstmt = ConnectionDB::con->prepareStatement("SELECT * FROM ticketsTable");
    result = pstmt->executeQuery();

        while (result->next())
        {
                Ticket t;
                t.setTicketId(result->getInt(1));
                t.setDestination(result->getString(2));
                t.setFlightNo(result->getInt(3));
                t.setDepartDate(result->getString(4));
                t.setUserId(result->getInt(5));

                ArrayTickets::arrayTickets.push_back(t);
        }
    
    delete pstmt;
    delete result;

    ArrayTickets::lastTicketId = ArrayTickets::getLastTicketId();

    return ArrayTickets::arrayTickets;
}


void ManagementDB::addTicket(Ticket& t)
{
    sql::PreparedStatement* pstmt;

    pstmt = ConnectionDB::con->prepareStatement("INSERT INTO ticketsTable (destination, flight_number, departure_date, user_id) VALUES(?,?,?,?)");

    pstmt->setString(1, t.getDestination());
    pstmt->setInt(2, t.getFlightNo());
    pstmt->setString(3, t.getDepartDate());
    pstmt->setInt(4, t.getUserId());


    try
    {
        pstmt->executeQuery();
    }
    catch (sql::SQLException e)
    {
        std::cout << " Error message: " << e.what() << std::endl;
        system("pause");
        exit(1);
    }

    std::cout << "ticket successfully created!\n\n";

    delete pstmt;
}

void ManagementDB::deleteTicket(int ticketId)
{
    sql::PreparedStatement* pstmt;

    pstmt = ConnectionDB::con->prepareStatement("DELETE FROM ticketsTable WHERE id_ticket = ?");
    pstmt->setInt(1, ticketId);
    pstmt->executeUpdate();
    std::cout << "\nticket number " << ticketId << " deleted\n";

    delete pstmt;
}

void ManagementDB::updateDestination(int ticketId, std::string newDest)
{
    sql::PreparedStatement* pstmt;

    pstmt = ConnectionDB::con->prepareStatement("UPDATE ticketsTable SET destination = ? WHERE id_ticket = ?");
    pstmt->setString(1, newDest);
    pstmt->setInt(2, ticketId);
    pstmt->executeQuery();

    std::cout << "destination successfully changed to: " << newDest << "\n";

    delete pstmt;
}

void ManagementDB::updateFlightNo(int ticketId, int newFlightNo)
{
    sql::PreparedStatement* pstmt;

    pstmt = ConnectionDB::con->prepareStatement("UPDATE ticketsTable SET flight_number = ? WHERE id_ticket = ?");
    pstmt->setInt(1, newFlightNo);
    pstmt->setInt(2, ticketId);
    pstmt->executeQuery();

    std::cout << "flight number successfully changed to: " << newFlightNo << "\n";

    delete pstmt;
}

void ManagementDB::updateDepartureDate(int ticketId, std::string newDepartDate)
{
    sql::PreparedStatement* pstmt;

    pstmt = ConnectionDB::con->prepareStatement("UPDATE ticketsTable SET departure_date = ? WHERE id_ticket = ?");
    pstmt->setString(1, newDepartDate);
    pstmt->setInt(2, ticketId);
    pstmt->executeQuery();

    std::cout << "departure date successfully changed to: " << newDepartDate << "\n";

    delete pstmt;
}

std::string ManagementDB::getUserName(int userId)
{
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;

    pstmt = ConnectionDB::con->prepareStatement("select user_name from userstable where user_id = ?");
    pstmt->setInt(1, userId);
    result = pstmt->executeQuery();

    result->next();
    std::string userName = result->getString("user_name");

    delete pstmt;
    delete result;

    return userName;
}
