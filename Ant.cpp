#include "Ant.h"
#include "Role.h"
#include <iostream>
using namespace std;

Ant::Ant(const std::string& name, std::shared_ptr<Role> initialRole, int a, int h) : age(a), health(h), role(initialRole)
{
}

Ant::~Ant()
{
    cout << "Ant is being destroyed \n";
}

void Ant::AgeOneYear()
{
    age++;
    updateRole();
}

void Ant::printInfo() const
{
    cout << "\nAge: " << age << "\n";
    cout << "Health:" << health << "\n";
    if (role) {
       // role->Work();  //No Work()
    }
    else
        cout << "This ant is baby" << "\n";
}

void Ant::checkAnt() const
{
    if (age > 30 || health <= 0)
        cout << "Dead" << endl;
    else
        cout << "Alive" << endl;
}

void Ant::updateRole() 
{
  
    if (age < 3) {
        role = nullptr;
    }
    else if (age < 10)
    {
        role = make_shared<NannyRole>();
    }
    else if (age < 20){
        role = make_shared<HarvesterRole>();
    }
    else if (age < 30){
        role = make_shared<BuilderRole>();
    }
    else{
         role = make_shared<SoldierRole>();
    }

}

std::string Ant::getName() const {
        return "This ant";
}

void Ant::setRole(std::shared_ptr<Role> newRole) {
     role = newRole;
}

void Ant::onEvent(const std::string& event){
        cout << getName() << " received event: " << event << std::endl;
        if (role) {
            role->onEvent(event);
        }
}