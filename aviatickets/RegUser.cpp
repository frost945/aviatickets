
#include "RegUser.h"

using namespace std;

void regUser()
{
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

	sql::Connection* con;
	sql::PreparedStatement* pstmt;

	con = connectionDB();
	pstmt = con->prepareStatement("INSERT INTO userstable (user_name, user_lastname, user_email, user_password) VALUES(?,?,?,?)");
	pstmt->setString(1, userName);
	pstmt->setString(2, userLastName);
	pstmt->setString(3, userEmail);
	pstmt->setString(4, userPassword);
	pstmt->executeQuery();

	cout << "user successfully created!\n\n";

	delete con;
	delete pstmt;
}