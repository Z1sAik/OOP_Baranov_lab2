#include "commander_Baranov.h"
#include "function_Baranov.h"
#include <iostream>

using namespace std;

void Commander::input() {
    Soldier::input();

    wcout << L"Введите общее количество нарядов командира: ";
    Tasks = readNumber<int>(0, 100);

    wcout << L"Выберите тип командира:\n";
    wcout << L"1. Заместитель командира взвода\n";
    wcout << L"2. Дежурный\n";
    wcout << L"3. Начальник смены\n";
    wcout << L"4. Старший солдат\n";
    wcout << L"Ваш выбор: ";
    Type = readNumber<int>(1, 4);
}

void Commander::output(const vector<shared_ptr<Soldier>>& squad) const {
    Soldier::output();
    wcout << L"Общее количество нарядов командира: " << Tasks << L"\n";

    int subCount = 0;
    for (const auto& s : squad) {
        if (dynamic_cast<Commander*>(s.get()) == nullptr)
            subCount++;
    }
    wcout << L"Подчиненные: " << subCount << L"\n";

    wstring typeStr;
    switch (Type) {
    case 1: typeStr = L"Заместитель командира взвода"; break;
    case 2: typeStr = L"Дежурный"; break;
    case 3: typeStr = L"Начальник смены"; break;
    case 4: typeStr = L"Старший солдат"; break;
    default: typeStr = L"Неизвестно"; break;
    }
    wcout << L"Тип командира: " << typeStr << L"\n";
}
