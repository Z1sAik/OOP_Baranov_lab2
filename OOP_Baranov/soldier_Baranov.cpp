#include "soldier_Baranov.h"
#include "function_Baranov.h"
#include <iostream>

using namespace std;

int Soldier::NextID = 0;

void Soldier::input() {
    ID = ++NextID;
    wcout << L"Введите имя: ";
    getline(wcin >> ws, Name);
    wcout << L"Введите фамилию: ";
    getline(wcin >> ws, Surname);
    wcout << L"Введите возраст: ";
    Age = readNumber<int>(18, 70);

    wcout << L"Выберите звание:\n"
        << L"1. Рядовой\n"
        << L"2. Ефрейтор\n"
        << L"3. М. Сержант\n"
        << L"4. Сержант\n"
        << L"5. С. Сержант\n"
        << L"6. Старшина\n"
        << L"Ваш выбор: ";
    RankID = readNumber<int>(1, 6);
}


void Soldier::output() const {
    wcout << L"Тип: " << getType() << L"\n";
    wcout << L"ID: " << ID << L"\n";
    wcout << L"Имя: " << Name << L"\n";
    wcout << L"Фамилия: " << Surname << L"\n";
    wcout << L"Возраст: " << Age << L"\n";
    wcout << L"Звание: " << rankToString(RankID) << L"\n";
}

std::wstring Soldier::rankToString(int id) {
    if (id == 1) return L"Рядовой";
    if (id == 2) return L"Ефрейтор";
    if (id == 3) return L"М. Сержант";
    if (id == 4) return L"Сержант";
    if (id == 5) return L"С. Сержант";
    if (id == 6) return L"Старшина";
    return L"Неизвестно";
}


