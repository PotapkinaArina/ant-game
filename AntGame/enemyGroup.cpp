#include "enemyGroup.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <numeric>  // Для std::accumulate
#include <algorithm> // Для std::shuffle

using namespace std;

Enemy::Enemy() {}

Enemy::Enemy(int groupSize)
{
    for (int i = 0; i < groupSize; ++i)
    {
        int health = rand() % (200 - 50 + 1) + 50;
        int strength = rand() % (15 - 5 + 1) + 5;
        enemies.emplace_back(health, strength); // Создаем и добавляем врага
    }
}

void Enemy::attackAntHill(std::vector<vector<Ant*> > ants)
{
    if (ants.empty())
    {
        std::cout << "The anthill is empty! There is no one to attack.\n";
        return;
    }

    //создаём вектор солдат и вектор остальных муравьёв
    std::vector<Ant*> soldiers;
    std::vector<Ant*> others;
    for (int i = 0; i < ants.size(); i++)
    {
        for (int j = 0; j < ants[i].size(); j++) {
            if (ants[i][j]->getCurrentRoleIndex() == 2 && ants[i][j]->getHealth() > 0) {
                soldiers.push_back(ants[i][j]); // Сохраняем указатель на солдата
            }
            else if (ants[i][j]->getHealth() > 0) {
                others.push_back(ants[i][j]); // Сохраняем указатель на не солдата
            }
        }
    }

    //2. начало атаки врагов
    for (EnemyIndividual& enemy : enemies) {
        if (!enemy.isAlive) continue; // Пропускаем мертвых врагов

        Ant* target = nullptr; //Цель для атаки

        //Выбираем случайную цель
        if (!soldiers.empty()) {
            //Если есть солдаты, выбираем случайного солдата
            target = soldiers[rand() % soldiers.size()];
        }
        else if (!others.empty()) {
            //Если нет солдат, выбираем случайного муравья
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

            //Удаляем муравья из списка (soldiers или others)
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
    //ДОБАВИЛА
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
    // Проверяем, есть ли хоть один живой враг в группе
    for (const auto& enemy : enemies) {
        if (enemy.isAlive) {
            return true;
        }
    }
    return false;
}

void Enemy::distributeDamage(int damage) {
    //Случайным образом распределяем урон между врагами
    while (damage > 0) {
        // Выбираем случайного живого врага
        vector<size_t> aliveEnemyIndices;
        for (size_t i = 0; i < enemies.size(); ++i) {
            if (enemies[i].isAlive) {
                aliveEnemyIndices.push_back(i);
            }
        }

        if (aliveEnemyIndices.empty()) return; // Все враги мертвы

        size_t targetIndex = aliveEnemyIndices[rand() % aliveEnemyIndices.size()];

        // Наносим урон
        int damageToApply = rand() % damage + 1;  //Наносим случайное кол-во урона
        enemies[targetIndex].health -= damageToApply;

        if (enemies[targetIndex].health <= 0) {
            enemies[targetIndex].isAlive = false;
            enemies[targetIndex].health = 0;
        }

        damage -= damageToApply;  //Уменьшаем общий урон
    }
}