#include "squad_Baranov.h"
#include "commander_Baranov.h"
#include "function_Baranov.h"
#include "exports_Baranov.h"
#include <iostream>
#include <boost/archive/text_woarchive.hpp>
#include <boost/archive/text_wiarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/export.hpp>
#include <fstream>

using namespace std;


void Squad_Baranov::input() {
    wcout << L"Кого добавить?\n";
    wcout << L"1. Солдата\n";
    wcout << L"2. Командира\n";
    wcout << L"Ваш выбор: ";
    int choice = readNumber<int>(1, 2);

    shared_ptr<Soldier_Baranov> s;
    if (choice == 1)
        s = make_shared<Soldier_Baranov>();
    else
        s = make_shared<Commander_Baranov>();

    s->input();
    Soldiers.push_back(s);

    wcout << L"Добавлен " << s->getType() << L".\n";
}


void Squad_Baranov::showAll() const {
    if (Soldiers.empty()) {
        std::wcout << L"Взвод пуст.\n";
        return;
    }

    for (const auto& s : Soldiers) {
        s->output();
        wcout << L"-----------------\n";
    }
}


void Squad_Baranov::clear() {
    Soldiers.clear();
    Soldier_Baranov::setNextID(0);
}


void Squad_Baranov::updateNextIDAfterLoad() {
    int maxID = 0;
    for (const auto& s : Soldiers) {
        if (s) {
            maxID = std::max(maxID, s->getID());
        }
    }
    Soldier_Baranov::setNextID(maxID);
}


void Squad_Baranov::saveToFile() const {
    wcout << L"Введите имя файла для сохранения (без расширения): ";
    wstring filename;
    getline(wcin >> ws, filename);
    if (filename.empty()) return;

    wofstream ofs(filename + L".txt");
    if (!ofs) { wcout << L"Не удалось открыть файл\n"; return; }

    boost::archive::text_woarchive oa(ofs);
    oa << Soldiers;
    wcout << L"Сохранение выполнено: " << filename << ".txt" << endl;
}


void Squad_Baranov::loadFromFile() {
    wcout << L"Введите имя файла для загрузки (без расширения): ";
    wstring filename;
    getline(wcin >> ws, filename);
    if (filename.empty()) return;

    wifstream ifs(filename + L".txt");
    if (!ifs) { wcout << L"Не удалось открыть файл\n"; return; }

    Soldiers.clear();
    boost::archive::text_wiarchive ia(ifs);
    ia >> Soldiers;
    updateNextIDAfterLoad();
    wcout << L"Загрузка выполнена: " << filename << ".txt" << endl;
}
