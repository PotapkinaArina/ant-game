#include "Anthill.h"

Anthill::Anthill() :
	
	size(NUM_ROLES* INITIAL_ANTS_PER_ROLE),
	capacity(size * 2),
	eat(0),
	branches(0),
	aphid(5),
	garbage(0),
	happyAphid(0),
	happyBaby(0)
{   
    std::vector<std::vector<Ant*>> home(NUM_ROLES, std::vector<Ant*>(INITIAL_ANTS_PER_ROLE));
    for(int i = 0; i < NUM_ROLES; i++)
        for (int j = 0; j < INITIAL_ANTS_PER_ROLE; j++)
        {
            home[i][j] = new Ant();
        }   
}

void Anthill::Update() {
    
    int maxAge = 30;

    for (int i = 0; i < home.size(); ++i)
    {
        for (int j = 0; j < home[i].size(); ++j)
        {
            home[i][j]->AgeOneYear();
        }
    }

    for (int i = 0; i < home.size(); ++i)
    {
        if (i == 6)
        {
            for (int j = home[i].size() - 1; j >= 0; --j)
            {
                if (home[i][j]->getAge() > maxAge)
                {
                    garbage++;
                    delete home[i][j];
                    home[i].erase(home[i].begin() + j);
                }
            }
        }
        else
        {
            int first_to_change_index = -1;
            for (int j = 0; j < home[i].size(); ++j)
            {
                Ant* ant = home[i][j];
                int old_role_index = i;
                int new_role_index = ant->getRoleIndex();

                if (old_role_index != new_role_index)
                {
                    first_to_change_index = j;
                    break;
                }
            }

            if (first_to_change_index != -1)
            {
                for (int j = first_to_change_index; j < home[i].size(); ++j)
                {
                    Ant* ant = home[i][j];

                    Role* new_role = ant->setRole();

                    int new_role_index = ant->getCurrentRoleIndex();

                    for (size_t k = 0; k < home[i].size(); ++k)
                    {
                        if (home[i][k] == ant) {
                            home[i].erase(home[i].begin() + k);
                            break;
                        }
                    }
                    home[new_role_index].push_back(ant);
                }
            }
        }
    }
}

