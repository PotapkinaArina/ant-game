#include "Role.h"
#include "Ant.h"
#include "Anthill.h";
using namespace std;

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
			home->babyGet(1);
			cout << home->babyCheck() - 1 << " children left" << endl;
		}
	}
	if (home->babyCheck() > 0) 
	{
		//food logics 
	}
}
void NannyRole::attackEnemy(Anthill* home)
{
}
void NannyRole::onEvent(const std::string& event, Anthill* home)
{
}
;


void SoldierRole::Work(Ant* ant, Anthill* home)
{
	std::cout << "Soldier is doing job" << std::endl;
}

void SoldierRole::attackEnemy(Anthill* home)
{
}

void SoldierRole::onEvent(const std::string& event, Anthill* home)
{
}

void ShepherdRole::Work(Ant* ant, Anthill* home)
{

	if (home->eatCheck() < 10)
	{
		//grazes aphids, food increases
	}
}

void ShepherdRole::attackEnemy(Anthill* home)
{
}

void ShepherdRole::onEvent(const std::string& event, Anthill* home)
{
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
		int flag = rand() % 10;
		if (flag == 0)
		{
			home->eatPlus();
		}
	}
}

void GathererRole::attackEnemy(Anthill* home)
{
}

void GathererRole::onEvent(const std::string& event, Anthill* home)
{
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

void BuilderRole::attackEnemy(Anthill* home)
{
}

void BuilderRole::onEvent(const std::string& event, Anthill* home)
{
}

void CleanerRole::Work(Ant* ant, Anthill* home)
{
	if (home->garbageCheck() > 0)
		home->garbageMinus();
}

void CleanerRole::attackEnemy(Anthill* home)
{
}

void CleanerRole::onEvent(const std::string& event, Anthill* home)
{
}
