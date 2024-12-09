
#include "PasswordDB.h"

using namespace std;

const string getPasswordDB()
{
	ifstream inf("passwordDB.txt");

	// Если мы не можем открыть этот файл для чтения его содержимого,
	if (!inf)
	{
		// то выводим следующее сообщение об ошибке и выполняем функцию exit()
		cerr << "Uh oh, SomeText.txt could not be opened for reading!" << endl;
		exit(1);
	}

	string passwordDB;
	inf >> passwordDB;

	return passwordDB;
}