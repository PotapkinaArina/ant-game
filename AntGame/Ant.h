#pragma once
#include <iostream>
#include <memory>
#include "Role.h"
using namespace std;

class Ant {
public:
	void Update() {
		age += 5;
		health--;
		RoleChange();
	}
	void RoleChange() {
		if (age < 2 || health < 10) return;
		if (age < 10) { newRole = std::make_unique<NannyRole>(); }
	}
private:
	int age = 0;
	std::unique_ptr<Role> newRole;
	int health = 100;
};