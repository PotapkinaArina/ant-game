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

void Ant::printInfo() const
{
    cout << "\nAge: " << age << "\n";
    cout << "Health:" << health << "\n";
}

Role* Ant::setRole()
{
    Role* new_role = nullptr;
    delete role;

    if (age < 3) {
        role = nullptr;
        currentRoleIndex = 0;
    }
    else if (age < 10) {
        new_role = new NannyRole();
        currentRoleIndex = 1;
    }
    else if (age < 20 && health>50) {
        new_role = new SoldierRole();
        currentRoleIndex = 2;
    }
    else if (age < 20 && health <= 50) {
        new_role = new ShepherdRole();
        currentRoleIndex = 3;
    }
    else if (age < 28 && health>30) {
        new_role = new BuilderRole();
        currentRoleIndex = 4;
    }
    else if (age < 28 && health <= 30) {
        new_role = new GathererRole();
        currentRoleIndex = 5;
    }
    else if (age <= 30) {
        new_role = new CleanerRole();
        currentRoleIndex = 6;
    }
    else {
        new_role = nullptr;
        currentRoleIndex = 7;
    }
    role = new_role;
    return new_role;
}

int Ant::getRoleIndex() const {
    if (age < 3) {
        return 0;
    }
    else if (age < 10) {
        return 1;
    }
    else if (age < 20 && health > 50) {
        return 2;
    }
    else if (age < 20 && health <= 50) {
        return 3;
    }
    else if (age < 28 && health > 30) {
        return 4;
    }
    else if (age < 28 && health <= 30) {
        return 5;
    }
    else if (age <= 30) {
        return 6;
    }
    else {
        return 7;
    }
} //return currentRoleIndex ?