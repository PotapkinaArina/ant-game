#pragma once
#include <iostream>
#include <vector>
#include "Ant.h"
#define NUM_ROLES 7
#define INITIAL 5
using namespace std;

class Ant;

class Anthill
{
private:
	int size;
	int eat;
	int branches;
	int capacity;
	int aphid;
	int garbage;
	int happyBaby;
	int happyAphid;
	int attackFlag;
	int resourcesFlag;

public:
	vector<vector<Ant*> > home;
	Anthill();
	~Anthill();
	void Update();
	int sizeCheck() { return size; }
	int eatCheck() { return eat; }
	int capacityCheck() { return capacity; }
	int branchesCheck() { return branches; }
	int aphidCheck() { return aphid; }
	int garbageCheck() { return garbage; }
	int happyBabyCheck() { return happyBaby; }
	int happyAphidCheck() { return happyAphid; }
	void happyBabyPlus() { happyBaby++; }
	void happyAphidPlus() { happyAphid++; }

	void sizePlus(int x);
	void sizeMinus(int x);
	void eatPlus(int x);
	void eatMinus(int x);
	void branchPlus(int x);
	void branchMinus(int x);
	void aphidPlus(int x);
	void aphidMinus(int x);
	void garbagePlus(int x);
	void garbageMinus(int x);

	int babyCheck() { return home[0].size(); }
	int NannyCheck() { return home[1].size(); }
	int SoldierCheck() { return home[2].size(); }
	int ShepherdCheck() { return home[3].size(); }
	int GathererCheck() { return home[4].size(); }
	int BuilderCheck() { return home[5].size(); }
	int CleanerCheck() { return home[6].size(); }

	vector<Ant*>& getBabies() { return home[0]; }
	vector<Ant*>& getSoldiers() { return home[2]; }
	void removeLastBaby();
	void performWork();
	void attackFlagChange() { attackFlag = 1; }
	int resourcesCheck();

	vector<vector<Ant*>>& getHome() { return home; }
	int babySet();
};