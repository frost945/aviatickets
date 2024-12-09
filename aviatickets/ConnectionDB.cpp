
#include "ConnectionDB.h"

using namespace std;

sql::Connection* connectionDB()
{
    const string server = "tcp://127.0.0.1:3306";
    const string username = "root";
    //const string password = "2048";
    const string password = getPasswordDB();


    sql::Driver* driver;
    sql::Connection* con;

    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    try
    {
        con->setSchema("aviaticketdb");
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to database. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }
    return con;
}

