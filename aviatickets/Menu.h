#pragma once

#include "Control.h"

enum ResultStartMenu
{
	USERLOG,
	USERREG,
	ADMINLOG,
	EXIT
};

class Menu
{
public:
	int menuStart();
	void menuUser(int userId);
	void menuAdmin();
};

