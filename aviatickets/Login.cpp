
#include "Login.h"

using std::cout; using std::cin; using std::string;


void Authorization::loginAdmin()
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


int Authorization::loginUser()
{
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;

	while (true)
	{
		cout << "enter password: ";
		string pasUser;
		cin >> pasUser;

		pstmt = ConnectionDB::con->prepareStatement("select exists (select user_password from userstable where user_password = ?)");
		pstmt->setString(1, pasUser);
		result = pstmt->executeQuery();

		result->next();

		if (result->getInt(1) != 0)
		{	
			cout << "login successful\n";
			delete pstmt;
			delete result; 
			int userId = getUserId(pasUser);
			return userId;
		}
		else cout << "wrong password, please try again\n";
	}
}
		
		
	
int Authorization::getUserId(std::string pasUser)
{
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;

	pstmt = ConnectionDB::con->prepareStatement("select user_id from userstable where user_password = ? ");
	pstmt->setString(1, pasUser);
	result=pstmt->executeQuery();

	result->next();
	int userId = result->getInt("user_id");
	//cout <<"userID " << userId << endl;//для проверки

	return userId;
}


void Authorization::regUser()
{
	using std::cout; using std::cin; using std::string;

	cout << "registration form\n";

	cout << "enter name: ";
	string userName;
	cin >> userName;

	cout << "\nenter last name: ";
	string userLastName;
	cin >> userLastName;

	cout << "\nenter email: ";
	string userEmail;
	cin >> userEmail;

	cout << "\nenter password: ";
	string userPassword;
	cin >> userPassword;

	sql::PreparedStatement* pstmt;

	pstmt = ConnectionDB::con->prepareStatement("INSERT INTO userstable (user_name, user_lastname, user_email, user_password) VALUES(?,?,?,?)");
	pstmt->setString(1, userName);
	pstmt->setString(2, userLastName);
	pstmt->setString(3, userEmail);
	pstmt->setString(4, userPassword);
	pstmt->executeQuery();

	cout << "user successfully created!\n\n";

	delete pstmt;
}