#pragma once
#include <iostream>
#include "Role.h"
using namespace std;

class Ant {
public:
	Ant(int a = 0, int h = 100);
	~Ant();
	Role* setRole();
	void AgeOneYear() { age++; }
	void healthPlus() { health++; }
	void healthMinus() { health--; }

	void printInfo()const;
	int getAge()const { return age; }
	int getHealth()const { return health; }
	Role* getRole()const { return role; }
	int getCurrentRoleIndex()const { return currentRoleIndex; }
	int getRoleIndex()const;

private:
	int age, health, currentRoleIndex = 0;
	Role* role = nullptr;
};
