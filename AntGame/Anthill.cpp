#include "Ant.h"
#include "Role.h"
#include "Anthill.h"

#include <iostream>
#include <set>
using namespace std;

Anthill::Anthill()
{
    size = 10;
    capacity = size * 2;
    eat = 10;
    branches = 0;
    aphid = 0;
    garbage = 0;

    home.resize(8);
    for (int i = 0; i < 8; ++i) {
        home[i] = std::vector<Ant*>(); //инициализация каждого вектора
    }

    for (int j = 0; j < 2; ++j)
    {
        Ant* ant = new Ant();
        home[0].push_back(ant);
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

void Anthill::Update()
{
    for (int i = 0; i < home.size() - 1; ++i)
    {
        for (int j = 0; j < home[i].size(); ++j)
        {
            home[i][j]->AgeOneYear();
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
}

