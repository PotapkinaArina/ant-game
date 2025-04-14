#pragma once
#include <iostream>
using namespace std;

class Ant;
class Anthill;

class Role {
public:
	virtual void onEvent(const std::string& event, Anthill* home) = 0;
	virtual void Work(Ant* ant, Anthill* home) = 0;
	virtual ~Role() {};
};

class NannyRole : public Role {
public:
	virtual void Work(Ant* ant, Anthill* home) override;
	void attackEnemy(Anthill* home);
	void onEvent(const std::string& event, Anthill* home) override;
};

class SoldierRole : public Role {
public:
    virtual void Work(Ant* ant, Anthill* home) override;
    void attackEnemy(Anthill* home);
    void onEvent(const std::string& event, Anthill* home) override;
};

class ShepherdRole : public Role {
public:
    virtual void Work(Ant* ant, Anthill* home) override;
    void attackEnemy(Anthill* home);
    void onEvent(const std::string& event, Anthill* home) override;
};

class GathererRole : public Role {
public:
    virtual void Work(Ant* ant, Anthill* home) override;
    void attackEnemy(Anthill* home);
    void onEvent(const std::string& event, Anthill* home) override;
};

class BuilderRole : public Role {
public:
    virtual void Work(Ant* ant, Anthill* home) override;
    void attackEnemy(Anthill* home);
    void onEvent(const std::string& event, Anthill* home) override;
};

class CleanerRole : public Role {
public:
    virtual void Work(Ant* ant, Anthill* home) override;
    void attackEnemy(Anthill* home);
    void onEvent(const std::string& event, Anthill* home) override;
};
