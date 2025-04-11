#pragma once
#include <iostream>;
#include <vector>;
#include "Ant.h";

class Anthill
{
private:
	vector<vector<Ant*>> home;
	int size;
	int eat;
	int branches;
	int capacity;
	int aphid;
	int garbage;
public:
	Anthill();
	~Anthill();
	void Update();
	int sizeCheck() { return size; }
	int eatCheck() { return eat; }
	int branchesCheck() { return branches; }
	int aphidCheck() { return aphid; }
	int garbageCheck() { return garbage; }
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
	int babyCheck() { return sizeof(home[0]);}
	int NannyCheck() { return sizeof(home[1]); }
	int SoldierCheck() { return sizeof(home[2]); }
	int ShepherdCheck() { return sizeof(home[3]); }
	int GathererCheck() { return sizeof(home[4]); }
	int BuilderCheck() { return sizeof(home[5]); }
	int CleanerCheck() { return sizeof(home[6]); }
	
	void babyGet(int x) 
	{ 
		if (sizeof(home[0]) - x >= 0)
		{
			for (int i = 0; i < x; i++)
			{
				//home[0][sizeof(home[0]) - 1]->die()
				home[0].pop_back();
				size--;
			}
		}
	}
	void babySet(int x) 
	{	
		for (int i = 0; i < x && i < x + size < capacity; i++)
		{
			//Ant* ant = home[0][sizeof(home[0]) - 1]->create()
			//home[0].push_back(ant);
			size++;
		}
	}

	void NannyGet(int x)
	{
		if (sizeof(home[1]) - x >= 0)
		{
			for (int i = 0; i < x; i++)
			{
				//home[1][sizeof(home[1]) - 1]->die()
				home[1].pop_back();
				size--;
			}
		}
	}

	void NannySet(int x)
	{
		for (int i = 0; i < x && i < x + size < capacity; i++)
		{
			//Ant* ant = home[1][sizeof(home[1]) - 1]->create()
			//home[1].push_back(ant);
			size++;
		}
	}

	void SoldeirGet(int x)
	{
		if (sizeof(home[2]) - x >= 0)
		{
			for (int i = 0; i < x; i++)
			{
				//home[2][sizeof(home[2]) - 1]->die()
				home[2].pop_back();
				size--;
			}
		}

	}

	void SoldeirSet(int x)
	{
		for (int i = 0; i < x && i < x + size < capacity; i++)
		{
			//Ant* ant = home[2][sizeof(home[2]) - 1]->create()
			//home[2].push_back(ant);
			size++;
		}
	}
};