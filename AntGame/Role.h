#pragma once
#include "Anthill.h"
#include "Ant.h"
#include <iostream>
using namespace std;

class Role {
public:
	
	virtual void onEvent(const std::string& event, Anthill* home) = 0;
	virtual void Work(Ant* ant, Anthill* home) = 0;
	virtual ~Role() = default;
};

class NannyRole : public Role {
public:
	virtual void Work(Ant* ant, Anthill* home) override;
	void attackEnemy(Anthill* home)
	{
		if (home->babyCheck() > 0)
		{
			if (home->happyBabyCheck() < home->babyCheck())
			{
				home->happyBabyPlus();
			}
		}
	}

	void onEvent(const std::string& event, Anthill* home) override {
		if (event == "AttackOnNest: Everyone, defend the nest!") {
			attackEnemy(home);
		}
	}
};

class SoldierRole : public Role
{
public:
	virtual void Work(Ant* ant, Anthill* home) override;
	void attackEnemy(Anthill* home)
	{

	};
	void onEvent(const std::string& event, Anthill* home) override {
		if (event == "AttackOnNest: Everyone, defend the nest!" || 
			event == "EnemyDetected: Soldiers to the rescue!") {
			attackEnemy(home);
		}
	}
};

class ShepherdRole : public Role
{
public:
	virtual void Work(Ant* ant, Anthill* home) override;
	void attackEnemy(Anthill* home)
	{
		if (home->aphidCheck() > 0)
		{
			if (home->happyAphidCheck() < home->aphidCheck())
			{
				home->happyAphidPlus();
			 
			}
		}
	}
	void onEvent(const std::string& event, Anthill* home) override {
		if (event == "AttackOnNest: Everyone, defend the nest!") {
			attackEnemy(home);
		}
	}
};

class GathererRole : public Role
{
public:
	virtual void Work(Ant* ant, Anthill* home) override;
	void attackEnemy(Anthill* home)
	{
		if (home->eatCheck() > 0)
		{
			
		}
	}
	void largeFood(Anthill* home)
	{	
		
		int flag = rand() % 5;
		if(flag == 0) home->eatPlus(); 
	};
	void onEvent(const std::string& event, Anthill* home) override {
		if (event == "AttackOnNest: Everyone, defend the nest!") {
			attackEnemy(home);
		}
		if (event == "LargeFoodSourceFound: Harvesters, gather round!")
		{
			largeFood(home);
		}
	}
};

class BuilderRole : public Role
{
public:
	virtual void Work(Ant* ant, Anthill* home) override;
	void attackEnemy(Anthill* home)
	{
		if (home->GathererCheck() - home->branchesCheck() < 0)
		{
			
		}
	}
	void BranchFound(Anthill* home) 
	{
		home->branchPlus(); 
	};
	void onEvent(const std::string& event, Anthill* home) override {
		if (event == "AttackOnNest: Everyone, defend the nest!") {
			attackEnemy(home);
		}
		if (event == "HeavyBranchFound: Builders, let's carry it!")
		{
			BranchFound(home);
		}
	}
};

class CleanerRole : public Role
{
public:
	virtual void Work(Ant* ant, Anthill* home) override;
	void clean(Anthill* home)
	{
		if (home->garbageCheck() > 0) home->garbageMinus();
	}
	void onEvent(const std::string& event, Anthill* home) override {
		if (event == "NestIsDirty: Cleaners, clean the nest!") {
			clean(home);
		}
	}
};