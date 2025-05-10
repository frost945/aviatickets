
#include "PasswordDB.h"


const std::string getPasswordDB()
{
	std::ifstream inf("passwordDB.txt");

	// ���� �� �� ����� ������� ���� ���� ��� ������ ��� �����������,
	if (!inf)
	{
		// �� ������� ��������� ��������� �� ������ � ��������� ������� exit()
		std::cerr << "Uh oh, SomeText.txt could not be opened for reading!" << std::endl;
		exit(1);
	}

	std::string passwordDB;
	inf >> passwordDB;

	return passwordDB;
}