
#include "ConnectionDB.h"


//int ConnectionDB::countCon = 0;

sql::Connection* ConnectionDB::con= connectionDB();

sql::Connection* ConnectionDB::connectionDB()
{
    //++countCon;//для проверки кол-ва вызовов функции

    const std::string server = "tcp://127.0.0.1:3306";
    const std::string username = "root";
    //const string password = "2048";
    const std::string password = getPasswordDB();


    sql::Driver* driver;
    sql::Connection* con;

    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
        system("pause");
        exit(1);
    }

    try
    {
        con->setSchema("aviaticketdb");
    }
    catch (sql::SQLException e)
    {
        std::cout << "Could not connect to database. Error message: " << e.what() << std::endl;
        system("pause");
        exit(1);
    }
    return con;
}

