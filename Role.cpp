#include "Role.h"
#include <iostream>

void SoldierRole::onEvent(const std::string& event) {
    if (event == "EnemyDetected: Soldiers to the rescue!") {
        std::cout << "Soldier is going to defend!" << std::endl;
    }
    if (event == "AttackOnNest: Everyone, defend the nest!") {
        std::cout << "Soldier is fiercely defending the nest!" << std::endl;
    }
}

void BuilderRole::onEvent(const std::string& event) {
    if (event == "HeavyBranchFound: Builders, let's carry it!") {
        std::cout << "Builder is helping to carry the branch!" << std::endl;
    }
    if (event == "AttackOnNest: Everyone, defend the nest!") {
        std::cout << "Builder is defending the nest!" << std::endl;
    }
}

void HarvesterRole::onEvent(const std::string& event) {
    if (event == "LargeFoodSourceFound: Harvesters, gather round!") {
        std::cout << "Harvester is gathering food!" << std::endl;
    }
    if (event == "AttackOnNest: Everyone, defend the nest!") {
        std::cout << "Harvester is defending the nest!" << std::endl;
    }
}

void NannyRole::onEvent(const std::string& event) {
    if (event == "AttackOnNest: Everyone, defend the nest!") {
        std::cout << "Nanny is saving the baby!" << std::endl;
    }
}

void CleanerRole::onEvent(const std::string& event) {
    if (event == "NestIsDirty: Cleaners, clean the nest!") {
        std::cout << "Cleaner is cleaning the nest!" << std::endl;
    }
}