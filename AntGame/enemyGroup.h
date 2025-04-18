#pragma once
#pragma once
#include "Ant.h"
#include <vector>

class Enemy {
public:
    Enemy();
    Enemy(int groupSize); 
    void attackAntHill(std::vector<vector<Ant*> > home); 
    void printInfo() const;

    bool isAlive() const; 
    int getGroupSize() const { return enemies.size(); }

private:
    struct EnemyIndividual {  
        int health;
        int strength;
        bool isAlive;

        EnemyIndividual(int h, int s) : health(h), strength(s), isAlive(true) {}
    };

    std::vector<EnemyIndividual> enemies;
    void distributeDamage(int damage);
};