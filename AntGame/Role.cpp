#include "Role.h"
#include "Ant.h"
#include "Anthill.h"

void NannyRole::Work(Ant* ant, Anthill* home)
{
	if (home->babyCheck() >= 10 && home->babyCheck() % 2 == 0)
	{
		cout << "Random event for you" << endl;
		int behavior = rand() % 2;
		if (behavior == 0) cout << "You are good Nanny, the kids are ok" << endl;
		else if (behavior == 1)
		{
			cout << "Oh no, your children are lost!" << endl;
			//потеря ребенка ?
			cout << home->babyCheck() - 1 << " children left" << endl;
		}
	}
	//кормление детей
	if (home->babyCheck() > 0 && home->eatCheck() > 0 
		&& home->happyBabyCheck() < home->babyCheck())
	{
		home->eatMinus();
		home->happyBabyPlus();
	}
};


void SoldierRole::Work(Ant* ant, Anthill* home)
{
	int flag = rand() % 10;
	if (flag == 0)
	{
		ant->healthPlus();
	}
}

void ShepherdRole::Work(Ant* ant, Anthill* home)
{

	if (home->eatCheck() < 10)
	{	
		int flag = rand() % 10;
		if (flag == 0)
		{	
			cout << "The ant got some tasty nectar" << endl;
			home->eatPlus();
		}
	}
}

void GathererRole::Work(Ant* ant, Anthill* home)
{
	if (home->sizeCheck() < 10)
	{	
		int flag = rand() % 10;
		if (flag == 0) 
		{	
			cout << "Gatherer find new branches" << endl;
			home->sizePlus(); 
		}
	}
	if (home->eatCheck() < 10)
	{
		int flag = rand() % 20;
		if (flag == 0)
		{
			home->eatPlus();
		}
	}
}

void BuilderRole::Work(Ant* ant, Anthill* home)
{
	if (home->branchesCheck() != 0 && home->sizeCheck() < 10)
	{	
		cout << "Builder improved the Anthill" << endl;
		home->branchMinus();
		home->sizePlus();
	}
}

void CleanerRole::Work(Ant* ant, Anthill* home)
{	
	int flag = rand() % 10;
	if (home->garbageCheck() > 0 && flag == 0)
		home->garbageMinus();
	else if (home->garbageCheck() > 0 && flag == 1)
		home->eatMinus();
}
