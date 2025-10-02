#include "soldier_Baranov.h"
#include <iostream>
#include <string>
#include "function_Baranov.h"
#include <fstream>

using namespace std;

int Soldier::NextID = 0;
 
wistream& operator>>(wistream& in, Soldier& s) {
    s.ID = ++Soldier::NextID;

    wcout << L"Введите имя: ";
    getline(in >> ws, s.Name);

    wcout << L"Введите фамилию: ";
    getline(in >> ws, s.Surname);

    wcout << L"Введите возраст: ";
    s.Age = readNumber<int>(1, 65);

    wcout << L"Выберите звание:" << endl;
    wcout << L"1. Рядовой" << endl;
    wcout << L"2. Ефрейтор" << endl;
    wcout << L"3. Сержант" << endl;
    wcout << L"4. Лейтенант" << endl;
    wcout << L"5. Капитан" << endl;
    wcout << L"Ваш выбор: ";
    s.RankID = readNumber<int>(1, 5);

    return in;
}

wstring Soldier::rankToString(int id) {
    switch (id) {
    case 1: return L"Рядовой";
    case 2: return L"Ефрейтор";
    case 3: return L"Сержант";
    case 4: return L"Лейтенант";
    case 5: return L"Капитан";
    default: return L"Неизвестно";
    }
}

wostream& operator<<(wostream& out, const Soldier& s) {
    out << L"ID: " << s.ID << endl;
    out << L"Имя: " << s.Name << endl;
    out << L"Фамилия: " << s.Surname << endl;
    out << L"Возраст: " << s.Age << endl;
    out << L"Звание: " << Soldier::rankToString(s.RankID) << endl;
    return out;
}

wofstream& operator<<(wofstream& fout, const Soldier& s) {
    fout << s.ID << endl;
    fout << s.Name << endl;
    fout << s.Surname << endl;
    fout << s.Age << endl;
    fout << s.RankID << endl;
    return fout;
}

wifstream& operator>>(wifstream& fin, Soldier& s) {
    if (!fin) return fin;
    fin >> s.ID;
    fin.ignore(10000, L'\n');
    getline(fin >> ws, s.Name);
    getline(fin >> ws, s.Surname);
    fin >> s.Age;
    fin >> s.RankID;
    fin.ignore(10000, L'\n');
    if (s.ID > Soldier::NextID) Soldier::NextID = s.ID;
    return fin;
}
