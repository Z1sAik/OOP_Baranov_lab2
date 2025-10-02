#include "squad_Baranov.h"
#include <iostream>

using namespace std;

void Squad::addSoldier() {
    Soldier* s = new Soldier();
    wcin >> *s;
    Soldiers.push_back(s);
}

void Squad::showAll() const {
    if (Soldiers.empty()) {
        wcout << L"Взвод пуст." << endl;
        return;
    }
    for (const Soldier* s : Soldiers) {
        wcout << *s << endl;
    }
}

void Squad::writeToFile(std::wofstream& fout) const {
    fout << Soldiers.size() << std::endl;
    for (auto soldier : Soldiers) {
        fout << *soldier;
    }
}

void Squad::readFromFile(std::wifstream& fin) {
    clear();
    int count;
    fin >> count;
    fin.ignore(10000, L'\n');
    for (int i = 0; i < count; i++) {
        Soldier* s = new Soldier();
        fin >> *s;
        Soldiers.push_back(s);
    }
}

void Squad::clear() {
    for (Soldier* s : Soldiers) {
        delete s;
    }
    Soldiers.clear();
}
