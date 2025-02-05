
#include "Menu.h"

using std::cout; using std::cin;

int Menu::menuStart()
{
    int select;

    while (true)
    {
        cout << "START PAGE\n";
        cout << "1-user login, 2-user registration, 3-admin login, 4-exit program\n";

        cin >> select;

        switch (select)
        {
        case 1: return USERLOG;
        case 2: return USERREG;
        case 3: return ADMINLOG;
        case 4: return EXIT;
        }
    }
}

void Menu::menuAdmin()
{
    ControlAdmin controlAdmin;
    OutputAdmin outputAdmin;

    while (true)
    {
        cout << "\nMENU_ADMIN\n";
        cout << "1-create ticket, 2-print all tickets, 3-delete a specific ticket,\n";
        cout << "4-redaction ticket, 5-exit program\n";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1: controlAdmin.creatTicket(); break;
        case 2: outputAdmin.readTickets(); break;
        case 3: controlAdmin.deleteTicket(); break;
        case 4: controlAdmin.updateTicket(); break;
        case 5: return;
        }
    }
}

void Menu::menuUser(int userId)
{
    ManagementDB manDB;
    ControlUser controlUser;
    OutputUser outputUser;

    while (true)
    {
        cout << "\n\nMENU_USER: \"" << manDB.getUserName(userId) << "\"\n";
        cout << "1-create ticket, 2-print ticket, 3-exit program\n";
        int select;
        cin >> select;

        switch (select)
        {
        case 1: controlUser.creatTicket(userId); break;
        case 2: outputUser.readTickets(userId); break;
        case 3: return;
        }
    }
}



