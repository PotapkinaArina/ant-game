#include "Ant.h"
#include "Anthill.h"
#include <algorithm> 
using namespace std;

Anthill::Anthill()
{
    size = 10;
    capacity = 100;
    eat = 50;
    branches = 10;
    aphid = 10;
    garbage = 0;
    attackFlag = 0;
    resourcesFlag = 0;
    happyAphid = happyBaby = 0;

    home.resize(NUM_ROLES);

    for (int i = 0; i < 7; ++i)
    {
        home[i].resize(INITIAL);
        for (int j = 0; j < INITIAL; ++j)
        {
            int flag = rand() % 2;
            int age = 0;
            int h = 0;
            if (i == 0)
            {
                age = 0;
                h = flag == 0 ? 100 : 50;
            }
            else if (i == 1)
            {
                age = 3;
                h = flag == 0 ? 100 : 50;
            }
            else if (i == 2)
            {
                age = 10;
                h = 100;
            }
            else if (i == 3)
            {
                age = 10;
                h = 50;
            }
            else if (i == 4)
            {
                age = 20;
                h = 100;
            }
            else if (i == 5)
            {
                age = 20;
                h = 30;
            }
            else if (i == 6)
            {
                age = 28;
                h = 100;
            }
            Ant* ant = new Ant(age, h);
            ant->changeCurrentRoleIndex(i);
            ant->setRole(this);
            home[i][j] = ant;
        }
    }
}

Anthill::~Anthill()
{

    for (int i = 0; i < home.size(); ++i)
    {
        for (int j = 0; j < home[i].size(); ++j)
        {
            delete home[i][j];
        }
        home[i].clear();
    }
    home.clear();
}

void Anthill::Update() {

    if (attackFlag == 1)
    {
        for (int i = 0; i < babyCheck() - happyBaby; i++)
        {
            removeLastBaby();
        }
        aphid = happyAphid;
        happyAphid = happyBaby = 0;
        branches = BuilderCheck() < branches ? BuilderCheck() : branches;
        eat = GathererCheck() + ShepherdCheck() < eat ? GathererCheck() + ShepherdCheck() : eat;
        attackFlag = 0;
    }

    for (int i = 0; i < home.size() - 1; ++i)
    {
        for (int j = home[i].size() - 1; j >= 0; --j)
        {
            home[i][j]->AgeOneYear();
            if (home[i][j]->getHealth() <= 0)
            {
                home[i][j]->~Ant();
                home[i].erase(home[i].begin() + j);
                garbagePlus(2);
            }
        }
    }

    for (int i = 0; i < home.size() - 1; ++i)
    {
        for (int j = home[i].size() - 1; j >= 0; --j)
        {
            if (home[i][j]->getUpdate())
            {
                Ant* ant = home[i][j];
                int oldRoleIndex = i;

                ant->setRole(this);
                ant->changeUpdate();
            }
        }
    }

    for (int i = 0; i < NannyCheck() - babyCheck(); i++)
    {
        int flag = babySet();
        if (flag == 1) break;
    }

}


void Anthill::removeLastBaby()
{
    if (!home[0].empty()) {
        delete home[0].back();
        home[0].pop_back();
    }
}

void Anthill::performWork()
{
    for (int i = 0; i < home.size(); i++) {
        for (int j = 0; j < home[i].size(); j++) {
            if (home[i][j]->getHealth() > 0 && home[i][j]->getRole()) {
                home[i][j]->getRole()->Work(home[i][j], this);
            }
        }
    }
}

int Anthill::resourcesCheck()
{
    if (size == 0 || eat == 0 || babyCheck() <= 0)
    {
        cout << "Anthill resources is over" << endl;
        return 1;
    }

    else
        return 0;

}

int Anthill::babySet()
{
    if (capacity > home.size())
    {
        cout << "A new baby was born!" << endl;
        Ant* ant = new Ant(0, 100);
        if (home[0].empty()) {
            home[0].push_back(ant);
        }
        else
        {
            home[0].insert(home[0].begin(), ant);
        }
        return 0;
    }
    else
    {
        cout << "No room for new ants" << endl;
        return 1;
    }
}

void Anthill::sizePlus(int x)
{
    int possibleIncrease = std::min(x, 10 - size);
    size += possibleIncrease;
    if (size >= 10) size = 10;
    else
        capacity = std::min(100, capacity + 2 * possibleIncrease);
}

void Anthill::sizeMinus(int x)
{
    int possibleDecrease = std::min(x, size);
    size -= possibleDecrease;
    if (size > 0) { capacity = std::max(0, capacity - 2 * possibleDecrease); };
    if (size < 0) {
        size = 0;
        resourcesFlag = 1;
    }
}

void Anthill::eatPlus(int x)
{
    eat = std::min(eat + x, 100);
}

void Anthill::eatMinus(int x)
{
    eat = std::max(eat - x, 0);
    if (eat == 0)
    {
        resourcesFlag = 1;
    }
}

void Anthill::branchPlus(int x)
{
    branches = std::min(branches + x, 10);
}

void Anthill::branchMinus(int x)
{
    branches = std::max(branches - x, 0);
    if (branches == 0) resourcesFlag = 1;
}

void Anthill::aphidPlus(int x)
{
    aphid = std::min(aphid + x, 10);
}

void Anthill::aphidMinus(int x)
{
    aphid = std::max(aphid - x, 0);
}

void Anthill::garbagePlus(int x)
{
    garbage += x;
}

void Anthill::garbageMinus(int x)
{
    garbage = std::max(garbage - x, 0);
}