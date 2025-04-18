#include "Ant.h"
#include "Role.h"
#include "Anthill.h"
#include "EventSystem.h"
#include <set>
#include <iostream>
#include <vector>
using namespace std;

Ant::Ant(int a, int h) :age(a), health(h), role(nullptr), currentRoleIndex(0)
{
}

Ant::~Ant()
{
    delete role;
}

set<int>s = { 3,10,20,28,31 };
void Ant::AgeOneYear()
{
    age++;
    if (s.count(age))
        needToUpdate = true;
    else
        needToUpdate = false;
}

void Ant::printInfo() const
{
    cout << "\nAge: " << age << "\n";
    cout << "Health:" << health << "\n";
}

string Ant::getRoleName(Ant* ant)
{
    int id = ant->getCurrentRoleIndex();
    if (id == 0) return "Baby";
    if (id == 1) return "Nanny";
    if (id == 2) return "Soldier";
    if (id == 3) return "Shepherd";
    if (id == 4) return "Gatherer";
    if (id == 5) return "Builder";
    if (id == 6) return "Cleaner";
    return "Unknown";
    return string();
}

void Ant::setRole(Anthill* home) {
    int oldRoleIndex = currentRoleIndex;

    if (role != nullptr) {
        delete role;
        role = nullptr;
    }

    if (age < 3) {
        currentRoleIndex = 0;
    }
    else if (age < 10) {
        role = new NannyRole();
        currentRoleIndex = 1;
    }
    else if (age < 20 && health>80) {
        role = new SoldierRole();
        currentRoleIndex = 2;
    }
    else if (age < 20 && health <= 80) {
        role = new ShepherdRole();
        currentRoleIndex = 3;
    }
    else if (age < 28 && health>50) {
        role = new BuilderRole();
        currentRoleIndex = 4;
    }
    else if (age < 28 && health <= 50) {
        role = new GathererRole();
        currentRoleIndex = 5;
    }
    else if (age <= 30) {
        role = new CleanerRole();
        currentRoleIndex = 6;
    }

    if (currentRoleIndex != oldRoleIndex) {
        home->home[currentRoleIndex].push_back(this);

        for (size_t i = 0; i < home->home[oldRoleIndex].size(); ++i) {
            if (home->home[oldRoleIndex][i] == this) {
                home->home[oldRoleIndex].erase(home->home[oldRoleIndex].begin() + i);
                break;
            }
        }
    }
}

void Ant::unsubscribeAll()
{
}

void Ant::subscribeBasedOnRole()
{
}