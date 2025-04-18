// EventSystem.h
#pragma once
#include <functional>
#include <vector>
#include <string>
#include <unordered_map>

class Anthill;

class EventNotifier {
private:
    std::unordered_map<std::string, std::vector<std::function<void(Anthill*)>>> subscribers;

public:
    void subscribe(const std::string& eventType, std::function<void(Anthill*)> callback);
    void unsubscribe(const std::string& eventType, std::function<void(Anthill*)> callback);
    void notify(const std::string& eventType, Anthill* home);
};


extern EventNotifier enemyNotifier;
extern EventNotifier foodNotifier;
extern EventNotifier buildingNotifier;
extern EventNotifier generalNotifier;

extern const std::string EVENT_ENEMY_ATTACK;
extern const std::string EVENT_SOLDIERS_HELP;
extern const std::string EVENT_LARGE_FOOD;
extern const std::string EVENT_HEAVY_BRANCH;
extern const std::string EVENT_NEST_DIRTY;
