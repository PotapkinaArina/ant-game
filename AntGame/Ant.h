#pragma once
#include <iostream>
#include "Role.h"

using namespace std;

class Ant {
public:
	Ant(int a = 0, int h = 100);
	~Ant();
	void AgeOneYear();
	void printInfo()const;
	void checkAnt()const;

private:
	int age, health;
	Role* role = nullptr;

protected:
	void setRole();
};
