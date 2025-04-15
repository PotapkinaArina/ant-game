#pragma once
#include <iostream>;
#include <vector>;
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
};