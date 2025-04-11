#pragma once
#include <iostream>
#include "Anthill.h";
#include "Ant.h";
#include "Informer.h";
using namespace std;

class Role {
public:
	virtual Informer* getInformer() = 0;
	virtual void onEvent(const std::string& event, Anthill* home) = 0;
	virtual void Work(Ant* ant, Anthill* home) = 0;
	virtual ~Role() {};
};

class NannyRole : public Role {
public:
	virtual void Work(Ant* ant, Anthill* home) override;
	/*Informer* getInformer() override {
		return Informer::AttackInformer;
	}*/
	
	void attackEnemy(Anthill* home) //спасение детей
	{
		if (home->babyCheck() > 0 )
		{

		}
	}

	void onEvent(const std::string& event, Anthill* home) override {
		if (event == "EnemyAttack") {
			attackEnemy(home);
		}
	}
};

class SoldierRole : public Role
{
public:
	virtual void Work(Ant* ant, Anthill* home) override;
};

class ShepherdRole : public Role
{
public:
	virtual void Work(Ant* ant, Anthill* home) override;
	/*Informer* getInformer() override {
		return Informer::AttackInformer;
	}*/
	void attackEnemy(Anthill* home)
	{
		if (home->aphidCheck() > 0)
		{

		}
	}
	void onEvent(const std::string& event, Anthill* home) override {
		if (event == "EnemyAttack") {
			attackEnemy(home);
		}
	}
};

class GathererRole : public Role
{
public:
	virtual void Work(Ant* ant, Anthill* home) override;
	/*Informer* getInformer() override {
		return Informer::AttackInformer;
	}*/
	void attackEnemy(Anthill* home)
	{
		if (home->eatCheck() > 0)
		{

		}
	}
	void onEvent(const std::string& event, Anthill* home) override {
		if (event == "EnemyAttack") {
			attackEnemy(home);
		}
	}
};

class BuilderRole : public Role
{
public:
	virtual void Work(Ant* ant, Anthill* home) override;
	/*Informer* getInformer() override {
	return Informer::AttackInformer;
}*/
	void attackEnemy(Anthill* home)
	{
		if (home->GathererCheck() - home->branchesCheck() < 0)
		{

		}
	}
	void onEvent(const std::string& event, Anthill* home) override {
		if (event == "EnemyAttack") {
			attackEnemy(home);
		}
	}
};

class CleanerRole : public Role
{
public:
	virtual void Work(Ant* ant, Anthill* home) override;
	/*Informer* getInformer() override {
	return Informer::AttackInformer;
}*/
	void attackEnemy(Anthill* home)
	{
		if (home->ShepherdCheck() - home->aphidCheck() < 0)
		{

		}
	}
	void onEvent(const std::string& event, Anthill* home) override {
		if (event == "EnemyAttack") {
			attackEnemy(home);
		}
	}
};