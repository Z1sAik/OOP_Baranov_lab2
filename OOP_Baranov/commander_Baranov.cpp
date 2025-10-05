#include "commander_Baranov.h"
#include "function_Baranov.h"
#include <iostream>
#include <boost/serialization/export.hpp>

void Commander::input() {
    Soldier::input();
    std::wcout << L"Введите количество наград: ";
    Awards = readNumber<int>(0, 100);
    std::wcout << L"Введите количество подчиненных: ";
    Subordinates = readNumber<int>(0, 1000);
    std::wcout << L"Выберите тип командира:\n1. Командир взвода\n2. Начальник смены\n3. Старший офицер\nВаш выбор: ";
    Type = readNumber<int>(1, 3);
}

void Commander::output() const {
    Soldier::output();
    std::wcout << L"Награды: " << Awards << L"\n";
    std::wcout << L"Подчиненные: " << Subordinates << L"\n";
    std::wstring typeStr = (Type == 1 ? L"Командир взвода" : (Type == 2 ? L"Начальник смены" : L"Старший офицер"));
    std::wcout << L"Тип командира: " << typeStr << L"\n";
}

