
#ifndef LOGIN_H
#define LOGIN_H

#include "ConnectionDB.h"
#include <cppconn/prepared_statement.h>


class Authorization
{
private:
	int getUserId(std::string pasUser);
public:
	int loginUser();
	void loginAdmin();
	void regUser();
};

#endif

