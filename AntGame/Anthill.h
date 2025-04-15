#pragma once
#include "Ant.h"
#include "Role.h"
#include <memory>
#include <iostream>
#include <vector>
#define NUM_ROLES 7
#define INITIAL_ANTS_PER_ROLE 5


class Anthill
{
private:
	std::vector<std::vector<Ant*>> home;
	int size;
	int eat;
	int branches;
	int capacity;
	int aphid;
	int garbage;
	int happyBaby;
	int happyAphid;
public:
	Anthill();
	~Anthill() {

		for (int i = 0; i < NUM_ROLES; i++)
			for (int j = 0; j < home[i].size(); j++)
			{	
				delete home[i][j];
			}
		home.clear();
	}
	void Update(); //the main function that works after the events
	
	//resources check 
	int sizeCheck() { return size; }
	int eatCheck() { return eat; }
	int branchesCheck() { return branches; }
	int aphidCheck() { return aphid; }
	int garbageCheck() { return garbage; }
	int happyBabyCheck() { return happyBaby; }
	int happyAphidCheck() { return happyAphid; }
	
	//resource management
	void sizePlus() { if (size++ <= 10) { size++; capacity += 5; }}
	void sizeMinus() { if (size-- >= 0) { size--; capacity -= 5; }}
	void eatPlus() { if (eat++ <= 10) eat++;;}
	void eatMinus() { if (eat-- >= 0) eat--; }
	void branchPlus() { if (branches ++ <= 10) branches++;  }
	void branchMinus() { if (branches-- >= 0) branches--; }
	void aphidPlus() { if (aphid++ <= 10) aphid++; }
	void aphidMinus() { if (aphid-- >= 0) aphid--; }
	void garbagePlus() { garbage++; }
	void garbageMinus() { if (garbage-- >= 0) garbage--;}
	void happyBabyPlus() { happyBaby++; }
	void happyAphidPlus() { happyAphid++; }
	
	//role count check
	int babyCheck() { return sizeof(home[0]);}
	int NannyCheck() { return sizeof(home[1]); }
	int SoldierCheck() { return sizeof(home[2]); }
	int ShepherdCheck() { return sizeof(home[3]); }
	int GathererCheck() { return sizeof(home[4]); }
	int BuilderCheck() { return sizeof(home[5]); }
	int CleanerCheck() { return sizeof(home[6]); }
};