
//программа позволяет создавать, хранить, редактировать, удалять и выводить на экран заявки на авиабилеты.
//реализация с записью и чтением из BD MySQL


#include "Login.h"
#include "Menu.h"


static void exeProgram()
{
    ManagementDB manDB;
    Menu menu;
    Authorization authoriz;

    if(manDB.checkRows()==0) std::cout << "no data in table \"ticketsTable\"\n";
    else ArrayTickets::arrayTickets = manDB.getDataTickets();

    while (true)
    {
        int res = menu.menuStart();

        switch (res)
        {
        case USERLOG: { int userId = authoriz.loginUser(); menu.menuUser(userId); break; }
        case USERREG: { authoriz.regUser(); break; }
        case ADMINLOG: { authoriz.loginAdmin(); menu.menuAdmin(); break; }
        case EXIT: {  return; }
        }
    }
    delete ConnectionDB::con;
}



int main()
{ 
    exeProgram();

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
