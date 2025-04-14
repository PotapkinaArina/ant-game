#pragma once
#include <iostream>
#include <memory>  
#include "Role.h"
#include "AntObserver.h" 

using namespace std;

class Ant : public AntObserver{
public:
    Ant(const std::string& name, std::shared_ptr<Role> initialRole, int a = 0, int h = 100);
    ~Ant();
    void AgeOneYear();
    void printInfo() const;
    void checkAnt() const;

    std::string getName() const; 

    void setRole(std::shared_ptr<Role> newRole); 
    void onEvent(const std::string& event) override; 

private:
    int age;
    int health;
    std::shared_ptr<Role> role; 

protected:
    void updateRole(); 
};