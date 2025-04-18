#include "enemyGroup.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

Enemy::Enemy() {}

Enemy::Enemy(int groupSize)
{
    for (int i = 0; i < groupSize; ++i)
    {
        int health = rand() % (200 - 50 + 1) + 50;
        int strength = rand() % (15 - 5 + 1) + 5;
        enemies.emplace_back(health, strength);
    }
}

void Enemy::attackAntHill(std::vector<vector<Ant*> > ants)
{
    if (ants.empty())
    {
        std::cout << "The anthill is empty! There is no one to attack.\n";
        return;
    }

    std::vector<Ant*> soldiers;
    std::vector<Ant*> others;
    for (int i = 0; i < ants.size(); i++)
    {
        for (int j = 0; j < ants[i].size(); j++) {
            if (ants[i][j]->getCurrentRoleIndex() == 2 && ants[i][j]->getHealth() > 0) {
                soldiers.push_back(ants[i][j]);
            }
            else if (ants[i][j]->getHealth() > 0) {
                others.push_back(ants[i][j]);
            }
        }
    }

    for (EnemyIndividual& enemy : enemies) {
        if (!enemy.isAlive) continue;

        Ant* target = nullptr;

        if (!soldiers.empty()) {
            target = soldiers[rand() % soldiers.size()];
        }
        else if (!others.empty()) {
            target = others[rand() % others.size()];
        }
        else
        {
            std::cout << "All the ants are dead\n";
            return;
        }

        int damage = enemy.strength;
        cout << "the enemy is attacking " << target->getRoleName(target) << " and deals " << damage << " damage.\n";
        target->healthMinus(damage);

        if (target->getHealth() <= 0) {
            std::cout << target->getRoleName(target) << " is dead!\n";

            if (target->getCurrentRoleIndex() == 2) {
                for (size_t i = 0; i < soldiers.size(); ++i) {
                    if (soldiers[i] == target) {
                        soldiers.erase(soldiers.begin() + i);
                        break;
                    }
                }
            }
            else {
                for (size_t i = 0; i < others.size(); ++i) {
                    if (others[i] == target) {
                        others.erase(others.begin() + i);
                        break;
                    }
                }
            }
        }
    }
    int enemies_damage = 0;
    for (int i = 0; i < soldiers.size(); i++)
    {
        if (soldiers[i]->getHealth() > 0)
            enemies_damage += soldiers[i]->getHealth();
    }
    distributeDamage(enemies_damage);
}


void Enemy::printInfo() const {
    cout << "Enemy Group Info:\n";
    for (size_t i = 0; i < enemies.size(); ++i) {
        cout << "Enemy " << i + 1 << ": Health = " << enemies[i].health
            << ", Strength = " << enemies[i].strength
            << ", Alive = " << enemies[i].isAlive << "\n";
    }
    cout << "\n";
}

bool Enemy::isAlive() const {
    for (const auto& enemy : enemies) {
        if (enemy.isAlive) {
            return true;
        }
    }
    return false;
}

void Enemy::distributeDamage(int damage) {
    while (damage > 0) {
        vector<size_t> aliveEnemyIndices;
        for (size_t i = 0; i < enemies.size(); ++i) {
            if (enemies[i].isAlive) {
                aliveEnemyIndices.push_back(i);
            }
        }

        if (aliveEnemyIndices.empty()) return; 

        size_t targetIndex = aliveEnemyIndices[rand() % aliveEnemyIndices.size()];

        int damageToApply = rand() % damage + 1; 
        enemies[targetIndex].health -= damageToApply;

        if (enemies[targetIndex].health <= 0) {
            enemies[targetIndex].isAlive = false;
            enemies[targetIndex].health = 0;
        }

        damage -= damageToApply; 
    }
}