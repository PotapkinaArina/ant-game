#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include "Role.h" 
#include "Ant.h"
#include "AntObserver.h" 



class Informer {
private:
    std::vector<std::weak_ptr<AntObserver>> subscribers;

public:
    void subscribe(std::shared_ptr<AntObserver> subscriber) {
        subscribers.push_back(subscriber);
        std::cout << "Subscriber added.\n";
    }

    void unsubscribe(std::shared_ptr<AntObserver> subscriber) {
        for (auto it = subscribers.begin(); it != subscribers.end();) {
            if (auto ptr = it->lock()) {
                if (ptr.get() == subscriber.get()) {
                    it = subscribers.erase(it);
                    std::cout << "Subscriber removed.\n";
                    break;
                } else {
                    ++it;
                }
            } else {
                it = subscribers.erase(it);
            }
        }
    }

    void notify(const std::string& message) {
         std::cout << "Notifier::Notify called! Message: " << message << ", Subscribers: " << subscribers.size() << "\n"; 
        for (auto it = subscribers.begin(); it != subscribers.end();) {
            if (auto subscriber = it->lock()) {
                subscriber->onEvent(message);
                ++it;
            } else {
                it = subscribers.erase(it);
            }
        }
    }
};


class EnemyInformer : public Informer {
public:
    void enemyDetected() {
        notify("EnemyDetected: Soldiers to the rescue!");
    }
};

class BranchInformer : public Informer {
public:
    void heavyBranchFound() {
        notify("HeavyBranchFound: Builders, let's carry it!");
    }
};

class FoodInformer : public Informer {
public:
    void largeFoodSourceFound() {
        notify("LargeFoodSourceFound: Harvesters, gather round!");
    }
};

class GeneralInformer : public Informer {
public:
    void attackOnNest() {
        notify("AttackOnNest: Everyone, defend the nest!");
    }
    void generalAlert(const std::string& message) {
        notify(message);
    }
};

class CleaningInformer : public Informer{
public:
    void nestIsDirty(){
        notify("NestIsDirty: Cleaners, clean the nest!");
    }
};

int main() {
  
    auto enemyInformer = std::make_shared<EnemyInformer>();
    auto branchInformer = std::make_shared<BranchInformer>();
    auto foodInformer = std::make_shared<FoodInformer>();
    auto generalInformer = std::make_shared<GeneralInformer>();
    auto cleaningInformer = std::make_shared<CleaningInformer>();

    
    auto soldierRole = std::make_shared<SoldierRole>();
    auto builderRole = std::make_shared<BuilderRole>();
    auto harvesterRole = std::make_shared<HarvesterRole>();
    auto nannyRole = std::make_shared<NannyRole>();
    auto cleanerRole = std::make_shared<CleanerRole>(); 

 
    auto antSoldier1 = std::make_shared<Ant>("Soldier1", soldierRole);
    auto antSoldier2 = std::make_shared<Ant>("Soldier2", soldierRole);
    auto antBuilder1 = std::make_shared<Ant>("Builder1", builderRole);
    auto antHarvester1 = std::make_shared<Ant>("Harvester1", harvesterRole);
    auto antNanny = std::make_shared<Ant>("Nanny", nannyRole);
    auto antCleaner1 = std::make_shared<Ant>("Cleaner1", cleanerRole); 
   
    enemyInformer->subscribe(antSoldier1);
    enemyInformer->subscribe(antSoldier2);
    branchInformer->subscribe(antBuilder1);
    foodInformer->subscribe(antHarvester1);
    generalInformer->subscribe(antNanny); 
    cleaningInformer->subscribe(antCleaner1); 

    
    std::cout << "---Simulating events---" << std::endl;

    enemyInformer->enemyDetected();
    branchInformer->heavyBranchFound();
    foodInformer->largeFoodSourceFound();
    generalInformer->attackOnNest();
    cleaningInformer->nestIsDirty(); 

    
    std::cout << "\n---Ant Role Change---" << std::endl;
    enemyInformer->unsubscribe(antSoldier1);
    generalInformer->subscribe(antSoldier1); 
    generalInformer->generalAlert("Help cleaning the nest!");
    antSoldier1.reset(); // the ant died :(
    generalInformer->attackOnNest(); // Test after an Ant is gone

    return 0;
}