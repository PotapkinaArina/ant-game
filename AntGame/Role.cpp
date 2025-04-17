#include "Role.h"
#include "Ant.h"
#include "Anthill.h"
using namespace std;

void NannyRole::Work(Ant* ant, Anthill* home)
{
	if (home->babyCheck() >= 10)
	{
		int behavior = rand() % 5;
		if (behavior == 0)
		{
			cout << "Oh no, your children are lost!" << endl;
			home->removeLastBaby();
			cout << home->babyCheck() - 1 << " children left" << endl;
		}
		else  cout << "You are good Nanny, the kids are ok" << endl;
	}

	if (home->babyCheck() > 0 && home->eatCheck() > 0)
	{
		auto& babies = home->getBabies();
		if (babies.empty()) return;
		// Поиск ребенка с минимальным здоровьем
		Ant* weakestBaby = nullptr;
		int minHealth = 100;

		for (auto baby : babies) {
			if (baby->getHealth() < minHealth) {
				minHealth = baby->getHealth();
				weakestBaby = baby;
			}
		}

		// Если есть ребенок, который не полностью здоров
		if (weakestBaby && weakestBaby->getHealth() < 100) {
			weakestBaby->healthPlus(10);
			home->eatMinus(1);
		}
	}
	// Все дети здоровы - кормим солдат
	else if (home->eatCheck() > 0 && home->SoldierCheck() > 0)
	{
		auto& soldiers = home->getSoldiers();
		if (!soldiers.empty()) {
			int index = rand() % soldiers.size();
			if (soldiers[index]->getHealth() < 100)
			{
				cout << "Nanny feeds the soldeirs" << endl;
				soldiers[index]->healthPlus(10);
				home->eatMinus(1);
			}
		}
	}
}
void NannyRole::attackEnemy(Anthill* home)
{
	if (home->happyBabyCheck() < home->babyCheck())
		home->happyBabyPlus();
};

void NannyRole::onEvent(const std::string& event, Anthill* home)
{
	if (event == "AttackOnNest: Everyone, defend the nest!") {
		attackEnemy(home);
	}
};



void SoldierRole::Work(Ant* ant, Anthill* home)
{
	std::cout << "Soldier is doing job" << std::endl;
	int flag = rand() % 5;
	if (flag == 0 && ant->getHealth() < 100)
	{
		ant->healthPlus(10);
	}
}

void SoldierRole::attackEnemy(Anthill* home)
{
	home->attackFlagChange();
}

void SoldierRole::onEvent(const std::string& event, Anthill* home)
{
	if (event == "AttackOnNest: Everyone, defend the nest!" ||
		event == "EnemyDetected: Soldiers to the rescue!") {
		attackEnemy(home);
	}
}


void ShepherdRole::Work(Ant* ant, Anthill* home)
{
	if (home->eatCheck() < 50 && home->aphidCheck() > 0)
	{
		int flag = rand() % 2;
		if (flag == 0)
		{
			cout << "The ant got some tasty nectar" << endl;
			home->eatPlus(5);
		}
	}
}

void ShepherdRole::attackEnemy(Anthill* home)
{
	if (home->happyAphidCheck() < home->aphidCheck())
	{
		home->happyAphidPlus();
	}
}

void ShepherdRole::onEvent(const std::string& event, Anthill* home)
{
	if (event == "AttackOnNest: Everyone, defend the nest!") {
		attackEnemy(home);
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
			home->sizePlus(1);
		}
	}
	if (home->eatCheck() < 10)
	{
		int flag = rand() % 10;
		if (flag == 0)
		{
			home->eatPlus(5);
		}
	}
}

void GathererRole::attackEnemy(Anthill* home)
{

}

void GathererRole::onEvent(const std::string& event, Anthill* home)
{
	if (event == "AttackOnNest: Everyone, defend the nest!") {
		attackEnemy(home);
	}
	if (event == "LargeFoodSourceFound: Harvesters, gather round!")
	{
		largeFood(home);
	}
}

void GathererRole::largeFood(Anthill* home)
{
	int flag = rand() % 2;
	if (flag == 0)
	{
		cout << "Work is in progress!" << endl;
		home->eatPlus(5);
	}
}

void BuilderRole::Work(Ant* ant, Anthill* home)
{
	if (home->branchesCheck() != 0 && home->sizeCheck() < 10)
	{
		cout << "Builder improved the Anthill" << endl;
		home->branchMinus(1);
		home->sizePlus(1);
	}
}

void BuilderRole::attackEnemy(Anthill* home)
{
}

void BuilderRole::onEvent(const std::string& event, Anthill* home)
{
	if (event == "AttackOnNest: Everyone, defend the nest!") {
		attackEnemy(home);
	}
	if (event == "HeavyBranchFound: Builders, let's carry it!")
	{
		BranchFound(home);
	}
}

void BuilderRole::BranchFound(Anthill* home)
{
	int flag = 0;
	flag = rand() % 2;
	if (home->branchesCheck() < 10 && flag == 1)
		home->branchPlus(rand() % 2 + 5);
}

void CleanerRole::Work(Ant* ant, Anthill* home)
{
	int flag = rand() % 2;
	if (home->garbageCheck() > 0 && flag == 0)
	{
		cout << "Clean Anthill" << endl;
		home->garbageMinus(1);
	}
}

void CleanerRole::attackEnemy(Anthill* home)
{
}

void CleanerRole::onEvent(const std::string& event, Anthill* home)
{
	if (event == "NestIsDirty: Cleaners, clean the nest!") {
		cleaning(home);
	};
}

void CleanerRole::cleaning(Anthill* home)
{
	if (home->garbageCheck() > 0) home->garbageMinus(1);
}