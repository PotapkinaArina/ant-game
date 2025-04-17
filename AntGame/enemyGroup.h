#pragma once
#pragma once
#include "Ant.h"
#include <vector>

class Enemy {
public:
    Enemy();
    Enemy(int groupSize); // Создаем группу врагов
    void attackAntHill(std::vector<vector<Ant*> > home); // Атака муравейника (группы муравьев)
    void printInfo() const;

    bool isAlive() const; // Проверяет, жива ли хоть одна особь в группе
    int getGroupSize() const { return enemies.size(); }

private:
    struct EnemyIndividual {  //Внутренняя структура для отдельного врага
        int health;
        int strength;
        bool isAlive;

        EnemyIndividual(int h, int s) : health(h), strength(s), isAlive(true) {}
    };

    std::vector<EnemyIndividual> enemies; // Вектор отдельных врагов
    void distributeDamage(int damage); // Метод для распределения урона по группе
};