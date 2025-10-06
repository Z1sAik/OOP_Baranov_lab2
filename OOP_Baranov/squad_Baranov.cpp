#include "squad_Baranov.h"
#include "commander_Baranov.h"
#include "function_Baranov.h"
#include <iostream>

using namespace std;

void Squad::addSoldierOnly() {
    auto s = make_shared<Soldier>();
    s->input();
    Soldiers.push_back(s);
}

void Squad::addCommanderOnly() {
    auto c = make_shared<Commander>();
    c->input();
    Soldiers.push_back(c);
}

void Squad::showAll() const {
    if (Soldiers.empty()) {
        std::wcout << L"Взвод пуст.\n";
        return;
    }

    for (const auto& s : Soldiers) {
        s->output();
        wcout << L"-----------------\n";
    }
}


void Squad::clear() {
    Soldiers.clear();
    Soldier::setNextID(0);
}

void Squad::updateNextIDAfterLoad() {
    int maxID = 0;
    for (const auto& s : Soldiers) {
        if (s) {
            maxID = std::max(maxID, s->getID());
        }
    }
    Soldier::setNextID(maxID);
}

