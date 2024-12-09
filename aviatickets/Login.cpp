
#include "Login.h"

using namespace std;

/*int login()
{
	while (true)
	{
		cout << "login as user, press 1\n";
		cout << "login as admin, press 2\n";

		int select;
		cin >> select;

		if (select == 1) loginUser();
		else if (select == 2) loginAdmin();
		else cout << "repeat your selection: ";
	}
}*/

void loginAdmin()
{
	cout << "enter password: ";
	int pasAdmin = 1024, pasInput;


	while (true)
	{
		cin >> pasInput;
		if (pasInput == pasAdmin)
		{
			cout << "login successful\n"; break;
		}

		else cout << "wrong password, please try again\n";
	}
}


int loginUser()
{
	sql::Connection* con;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;

	con = connectionDB();
	pstmt = con->prepareStatement("select user_password from userstable");
	result = pstmt->executeQuery();

	cout << "enter password: ";
	string pasInput, pasUser;

	while (true)
	{
		cin >> pasInput;

		while (result->next())
		{
			//cout << result->getString(1)<<endl;
			pasUser = result->getString(1);
			if (pasInput == pasUser)
			{
				cout << "login successful";     
				delete con;
				delete pstmt;
				delete result; int userId=getUserId(pasUser);	return userId;
			}
		}
		result->beforeFirst();// для того чтобы прогнать столбец паролей заново
		cout << "wrong password, please try again\n";
	}
}
		
		

		

		
	
int getUserId(std::string pasUser)
{
	sql::Connection* con;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;

	con = connectionDB();
	pstmt = con->prepareStatement("select user_id from userstable where user_password = ? ");
	pstmt->setString(1, pasUser);
	result=pstmt->executeQuery();

	result->next();
	int userId = result->getInt("user_id");
	//cout <<"userID " << userId << endl;//для проверки

	return userId;
}
