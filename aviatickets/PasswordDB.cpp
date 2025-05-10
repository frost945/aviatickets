
#include "PasswordDB.h"


const std::string getPasswordDB()
{
	std::ifstream inf("passwordDB.txt");

	// Если мы не можем открыть этот файл для чтения его содержимого,
	if (!inf)
	{
		// то выводим следующее сообщение об ошибке и выполняем функцию exit()
		std::cerr << "Uh oh, SomeText.txt could not be opened for reading!" << std::endl;
		exit(1);
	}

	std::string passwordDB;
	inf >> passwordDB;

	return passwordDB;
}