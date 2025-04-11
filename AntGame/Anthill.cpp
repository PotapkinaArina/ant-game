#include "Anthill.h"

Anthill::Anthill()
{
	size = 10;
	capacity = size * 2;
	eat = 10;
	branches = 0;
	aphid = 0;
	garbage = 0;
	for(int i = 0; i < 7; i++)
		for (int j = 0; j < 5; j++)
		{
			//home[i][j].push_back(create());
		}
}

Anthill::~Anthill()
{	

	for (int i = 0; i < 7; i++)
		for (int j = 0; j < sizeof(home[i]); j++)
		{
			//home[i][j].pop_back();
		}
}

void Anthill::Update()
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < sizeof(home[i]); j++)
		{
			//increase in age
			//removal of dead
			//adding children if there are resources
			//role change start
			//output current parameters
		}
}

