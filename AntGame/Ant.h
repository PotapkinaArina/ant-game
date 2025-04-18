#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>  
#include "Anthill.h"
#include "Role.h"
#include "EventSystem.h"
using namespace std;

class Ant {
public:
	Ant(int a = 0, int h = 100);
	~Ant();
	void setRole(Anthill* home);

	void AgeOneYear();
	void healthPlus(int x) { health += x; }
	void healthMinus(int x) { health -= x; }
	void changeUpdate() { needToUpdate = !needToUpdate; }
	void changeCurrentRoleIndex(int i) { currentRoleIndex = i; }

	void printInfo()const;
	int getAge()const { return age; }
	int getHealth()const { return health; }
	Role* getRole()const { return role; }
	string getRoleName(Ant* ant);
	int getCurrentRoleIndex()const { return currentRoleIndex; }
	bool getUpdate()const { return needToUpdate; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	int getX() const { return x; }
	int getY() const { return y; }

private:
	int age, health, currentRoleIndex = 0;
	Role* role = nullptr;
	bool needToUpdate = false;
	int x = 0;
	int y = 0; 
	void unsubscribeAll();
	void subscribeBasedOnRole();
};