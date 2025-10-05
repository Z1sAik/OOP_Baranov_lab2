#include "squad_Baranov.h"
#include "commander_Baranov.h"
#include "function_Baranov.h"
#include <iostream>

void Squad::addSoldier() {
    std::wcout << L"Выберите тип объекта:\n1. Солдат\n2. Командир\nВаш выбор: ";
    int choice = readNumber<int>(1, 2);

    std::shared_ptr<Soldier> s;
    if (choice == 2)
        s = std::make_shared<Commander>();
    else
        s = std::make_shared<Soldier>();

    s->input();
    Soldiers.push_back(s);
}

void Squad::showAll() const {
    if (Soldiers.empty()) {
        std::wcout << L"Взвод пуст.\n";
        return;
    }
    for (const auto& s : Soldiers) {
        s->output();
        std::wcout << L"-----------------\n";
    }
}

void Squad::clear() {
    Soldiers.clear();
}

void Squad::updateNextIDAfterLoad() {
    int maxID = 0;
    for (const auto& sp : Soldiers) {
        if (sp) {
            int id = sp->getID();
            if (id > maxID) maxID = id;
        }
    }
    Soldier::setNextID(maxID);
}
