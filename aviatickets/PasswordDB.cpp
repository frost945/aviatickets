
#include "PasswordDB.h"

using namespace std;

const string getPasswordDB()
{
	ifstream inf("passwordDB.txt");

	// ���� �� �� ����� ������� ���� ���� ��� ������ ��� �����������,
	if (!inf)
	{
		// �� ������� ��������� ��������� �� ������ � ��������� ������� exit()
		cerr << "Uh oh, SomeText.txt could not be opened for reading!" << endl;
		exit(1);
	}

	string passwordDB;
	inf >> passwordDB;

	return passwordDB;
}