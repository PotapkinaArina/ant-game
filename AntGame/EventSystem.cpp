#include "EventSystem.h"
#include "Anthill.h"
#include <algorithm> 


void EventNotifier::subscribe(const std::string& eventType, std::function<void(Anthill*)> callback) {
    subscribers[eventType].push_back(callback);
}

void EventNotifier::unsubscribe(const std::string& eventType, std::function<void(Anthill*)> callback) {
    auto& callbacks = subscribers[eventType];
    callbacks.erase(
        std::remove_if(callbacks.begin(), callbacks.end(),
            [&callback](const std::function<void(Anthill*)>& cb) {
                return &cb == &callback;
            }),
        callbacks.end());
}

void EventNotifier::notify(const std::string& eventType, Anthill* home) {
    auto it = subscribers.find(eventType);
    if (it != subscribers.end()) {
        for (auto& callback : it->second) {
            if (callback) {
                callback(home);
            }
        }
    }
}


extern EventNotifier enemyNotifier;
extern EventNotifier foodNotifier;
extern EventNotifier buildingNotifier;
extern EventNotifier generalNotifier;


const std::string EVENT_ENEMY_ATTACK = "AttackOnNest: Everyone, defend the nest!";
const std::string EVENT_SOLDIERS_HELP = "EnemyDetected: Soldiers to the rescue!";
const std::string EVENT_LARGE_FOOD = "LargeFoodSourceFound: Harvesters, gather round!";
const std::string EVENT_HEAVY_BRANCH = "HeavyBranchFound: Builders, let's carry it!";
const std::string EVENT_NEST_DIRTY = "NestIsDirty: Cleaners, clean the nest!";
