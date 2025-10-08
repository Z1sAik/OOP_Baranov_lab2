#include "squad_Baranov.h"
#include "commander_Baranov.h"
#include "function_Baranov.h"
#include <iostream>

using namespace std;

void Squad::input() {
    wcout << L"Кого добавить?\n";
    wcout << L"1. Солдата\n";
    wcout << L"2. Командира\n";
    wcout << L"Ваш выбор: ";
    int choice = readNumber<int>(1, 2);

    shared_ptr<Soldier> s;
    if (choice == 1)
        s = make_shared<Soldier>();
    else
        s = make_shared<Commander>();

    s->input();
    Soldiers.push_back(s);

    wcout << L"Добавлен " << s->getType() << L".\n";
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

