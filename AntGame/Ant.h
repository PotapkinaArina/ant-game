#pragma once
#include <iostream>
#include "Anthill.h"
#include "Role.h"
using namespace std;

class Ant {
public:
	Ant(int a = 0, int h = 100);
	~Ant();
	void setRole(Anthill* home);

	void AgeOneYear();
	void healthPlus() { health++; }
	void healthMinus() { health--; }
	void changeUpdate() { needToUpdate = !needToUpdate; }

	void printInfo()const;
	int getAge()const { return age; }
	int getHealth()const { return health; }
	Role* getRole()const { return role; }
	int getCurrentRoleIndex()const { return currentRoleIndex; }
	bool getUpdate()const { return needToUpdate; }

private:
	int age, health, currentRoleIndex = 0;
	Role* role = nullptr;
	bool needToUpdate = false;
};
