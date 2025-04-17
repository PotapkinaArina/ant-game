#include <iostream>
#include "Ant.h"
#include "Role.h"
#include "enemyGroup.h"
using namespace std;
int GameOverFlag = 0;

void printAnthillState(Anthill& home) {
    cout << "  Size: " << home.sizeCheck() << endl;
    cout << "  Capacity: " << home.capacityCheck() << endl;
    cout << "  Garbage: " << home.garbageCheck() << endl;
    cout << " Eat: " << home.eatCheck() << endl;
    cout << " Branches " << home.branchesCheck() << endl;
    cout << " Aphid " << home.aphidCheck() << endl;
}

void GameOver(Anthill& home)
{
    cout << "Game over. The state of your anthill at the end of the game : " << endl;
    printAnthillState(home);
    home.~Anthill();
}

void printAntDetails(Anthill& home) {
    cout << "  Ant Details (By Role):" << endl;
    for (int roleIndex = 0; roleIndex < 7; ++roleIndex) {
        if (home.home[roleIndex].empty()) {
            cout << "      No ants in this role." << endl;
            continue;
        }
        for (int antIndex = 0; antIndex < home.home[roleIndex].size(); ++antIndex) {
            Ant* ant = home.home[roleIndex][antIndex];
            cout << "      Ant at [" << roleIndex << "][" << antIndex << "]:" << endl;
            cout << "        Age: " << ant->getAge() << endl;
            cout << "        Health: " << ant->getHealth() << endl;
            cout << "        Role: " << ant->getRoleName(ant) << endl;
        }
    }
}

void applyFire(Anthill& home)
{
    int damage = rand() % 2 + 1;
    home.aphidMinus(damage);
    home.eatMinus(damage * 2);
    home.branchMinus(damage);
    home.sizeMinus(damage);

    for (int i = 0; i < 7; i++) {
        if (i == 2) continue;
        for (int j = 0; j < home.home[i].size(); j++)
        {
            home.home[i][j]->healthMinus(10);
        }
    }
    home.Update();
    home.performWork();
    GameOverFlag = home.resourcesCheck();
    cout << "Anthill condition" << endl;
    printAntDetails(home);
    cout << "Home detailes : " << endl;
    printAnthillState(home);
}

void simulateDay(Anthill& home)
{
    if (GameOverFlag)
    {
        GameOver(home);
        return;
    }
    int event = rand() % 2;
    if (event == 0)
    {
        Enemy enemies(20);
        cout << "Enemies attack!" << endl;
        enemies.attackAntHill(home.getHome());
        cout << "The attack is over!" << endl;

        home.attackFlagChange();
        home.Update();
        home.performWork();
        GameOverFlag = home.resourcesCheck();
        cout << "Anthill condition" << endl;
        printAntDetails(home);
        cout << "Home detailes : " << endl;
        printAnthillState(home);
        return;
    }
    else if (event == 1)
    {
        cout << "Forest fire!" << endl;
        applyFire(home);

        return;
    }
}


int main() {


    Anthill home;
    srand(static_cast<unsigned int>(time(0)));
    cout << "Start of the Ant Game" << endl;
    cout << "Anthill created." << endl;
    cout << "Home detailes : " << endl;
    printAnthillState(home);
    cout << "Ants : " << endl;
    printAntDetails(home);

    for (int day = 0; day < 30 && GameOverFlag != 1; ++day) {
        simulateDay(home);
    }

    return 0;
}