#pragma once
#include <iostream>
#include <memory>
using namespace std;

class Role {
public:
	virtual void Work(class Ant* ant) = 0;
	virtual ~Role() {};
};

class NannyRole : public Role {
public:
	void Work(Ant* ant) override { cout << "Nanny work" << endl; }
};