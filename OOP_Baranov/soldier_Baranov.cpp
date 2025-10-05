#include "soldier_Baranov.h"
#include <boost/serialization/export.hpp>
#include "function_Baranov.h"
#include <iostream>

int Soldier::NextID = 0;

void Soldier::input() {
    ID = ++NextID;
    std::wcout << L"Введите имя: ";
    std::getline(std::wcin >> std::ws, Name);
    std::wcout << L"Введите фамилию: ";
    std::getline(std::wcin >> std::ws, Surname);
    std::wcout << L"Введите возраст: ";
    Age = readNumber<int>(1, 65);
    std::wcout << L"Выберите звание:\n1. Рядовой\n2. Ефрейтор\n3. Сержант\n4. Лейтенант\n5. Капитан\nВаш выбор: ";
    RankID = readNumber<int>(1, 5);
}

void Soldier::output() const {
    std::wcout << L"ID: " << ID << L"\n";
    std::wcout << L"Имя: " << Name << L"\n";
    std::wcout << L"Фамилия: " << Surname << L"\n";
    std::wcout << L"Возраст: " << Age << L"\n";
    std::wcout << L"Звание: " << rankToString(RankID) << L"\n";
}

std::wstring Soldier::rankToString(int id) {
    switch (id) {
    case 1: return L"Рядовой";
    case 2: return L"Ефрейтор";
    case 3: return L"Сержант";
    case 4: return L"Лейтенант";
    case 5: return L"Капитан";
    default: return L"Неизвестно";
    }
}