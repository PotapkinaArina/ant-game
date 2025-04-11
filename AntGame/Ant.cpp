#include "Ant.h"
#include "Role.h"
#include <iostream>
using namespace std;

Ant::Ant(int a, int h) :age(a), health(h)
{
	setRole();
}

Ant::~Ant()
{
	delete role;
}

void Ant::AgeOneYear()
{
	age++;
	setRole();
}

void Ant::printInfo() const
{
	cout << "\nAge: " << age << "\n";
	cout << "Health:" << health << "\n";
	/*if (role)
		role->Work();
	else
		cout << "This ant is baby" << "\n";*/
}

void Ant::checkAnt() const
{
	if (age > 30 || health <= 0)
		cout << "Dead" << endl;
	else
		cout << "Alive" << endl;

}

void Ant::setRole()
{
	delete role;   
	if (age < 3) {
		role = nullptr;
	}
	else
	{
		role = new NannyRole;
		role->Work(this);
	}
}
