#include <iostream>
#include "Anthill.h"
#include "Ant.h"
#include "Role.h"

using namespace std;

// Функция для получения имени роли
string getRoleName(Role* role) {
    if (role == nullptr) return "None";
    if (dynamic_cast<NannyRole*>(role)) return "Nanny";
    if (dynamic_cast<SoldierRole*>(role)) return "Soldier";
    if (dynamic_cast<ShepherdRole*>(role)) return "Shepherd";
    if (dynamic_cast<GathererRole*>(role)) return "Gatherer";
    if (dynamic_cast<BuilderRole*>(role)) return "Builder";
    if (dynamic_cast<CleanerRole*>(role)) return "Cleaner";
    return "Unknown";
}

void printAnthillState(Anthill& home) {
    cout << "  Size: " << home.sizeCheck() << endl;
    cout << "  Capacity: " << home.capacityCheck() << endl;
    cout << "  Garbage: " << home.garbageCheck() << endl;
}

void printAntDetails(Anthill& home) {
    cout << "  Ant Details (By Role):" << endl;
    for (int roleIndex = 0; roleIndex < 7; ++roleIndex) {
        cout << "    Role " << roleIndex << ":" << endl;
        if (home.home[roleIndex].empty()) {
            cout << "      No ants in this role." << endl;
            continue;
        }
        for (int antIndex = 0; antIndex < home.home[roleIndex].size(); ++antIndex) {
            Ant* ant = home.home[roleIndex][antIndex];
            cout << "      Ant at [" << roleIndex << "][" << antIndex << "]:" << endl;
            cout << "        Age: " << ant->getAge() << endl;
            cout << "        Health: " << ant->getHealth() << endl;
            cout << "        Current Role Index: " << ant->getCurrentRoleIndex() << endl;
            cout << "        Role: " << getRoleName(ant->getRole()) << endl;
        }
    }
}

int main() {
    cout << "Start of the Ant Game - Detailed Update Test" << endl;

    // 1. Создание муравейника
    Anthill home;
    cout << "Anthill created." << endl;

    // 2. Печать изначального состояния муравейника
    cout << "\n--- Initial Anthill State ---" << endl;
    printAnthillState(home);

    // 3. Применение обновлений и отслеживание изменений
    for (int update_count = 1; update_count <= 3; ++update_count) { // Увеличение итераций
        cout << "\n--- Update() #" << update_count << " ---" << endl;
        home.Update();

        cout << "  Anthill State after Update #" << update_count << ":" << endl;
        printAnthillState(home);

        // 4. Печать деталей о каждом муравье
        printAntDetails(home);
    }

    cout << "\nAnt Game - Detailed Update Test completed." << endl;
    return 0;
}