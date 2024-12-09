// aviatickets.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Практические задания по С++. задание 3
//программа позволяет создавать, хранить, редактировать, удалять и выводить на экран заявки на авиабилеты.
//реализация с записью и чтением из DB


#include "ConnectionDB.h"
#include "RegUser.h"
#include "Login.h"
#include "Control.h"
#include "Output.h"

using namespace std;

void menuAdmin(Control& control, OutputAdmin& output)
{
    while (true)
    {
        cout << "\nMENU_ADMIN\n";
        cout << "1-create ticket, 2-print all tickets, 3-delete a specific ticket,\n";
        cout << "4-redaction ticket, 5-exit program\n";
        int choice;
        cin >> choice;

        switch (choice)
        {
       // case 1: control.creatTicket(); break;
        case 2: output.printTicket(); break;
        case 3: control.deleteTicket(); break;
        case 4: control.updateTicket(); break;
        case 5: return;
        }
    }
}

void menuUser(Control& control, OutputUser& outputUser, int userId)
{
    while (true)
    {
        cout << "\nMENU_USER\n";
        cout << "1-create ticket, 2-print ticket, 3-exit program\n";
        int select;
        cin >> select;

        switch (select)
        {
        case 1: control.creatTicket(userId); break;
        case 2: outputUser.printTicketUser(userId); break;
        case 3: return;
        }
    }
}

void menuStart(Control& control, OutputAdmin& outputAdmin, OutputUser& outputUser)
{
    int select;

    while (true)
    {
        cout << "WELCOME\n";
        cout << "1-user login, 2-register, 3-admin login, 4-exit program\n";

        cin >> select;

        switch (select)
        {
        case 1: { int userId = loginUser(); menuUser(control, outputUser, userId); break; }
        case 2: { regUser(); break; }
        case 3: { loginAdmin(); menuAdmin(control, outputAdmin); break; }
        case 4:return;
        }
    }
}



int main()
{ 
    connectionDB();

    Control control;
    OutputAdmin outputAdmin;
    OutputUser outputUser;

   menuStart(control, outputAdmin, outputUser);


    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
