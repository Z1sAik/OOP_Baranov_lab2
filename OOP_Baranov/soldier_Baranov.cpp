#include "soldier_Baranov.h"
#include <iostream>
#include <string>
#include "function_Baranov.h"
#include <fstream>

using namespace std;

int Soldier::NextID = 0;

wistream& operator>>(wistream& in, Soldier& s) {
    s.ID = ++Soldier::NextID;

    wcout << L"������� ���: ";
    getline(in >> ws, s.Name);

    wcout << L"������� �������: ";
    getline(in >> ws, s.Surname);

    wcout << L"������� �������: ";
    s.Age = readNumber<int>(1, 65);

    wcout << L"�������� ������:" << endl;
    wcout << L"1. �������" << endl;
    wcout << L"2. ��������" << endl;
    wcout << L"3. �������" << endl;
    wcout << L"4. ���������" << endl;
    wcout << L"5. �������" << endl;
    wcout << L"��� �����: ";
    s.RankID = readNumber<int>(1, 5);

    return in;
}

wstring Soldier::rankToString(int id) {
    switch (id) {
    case 1: return L"�������";
    case 2: return L"��������";
    case 3: return L"�������";
    case 4: return L"���������";
    case 5: return L"�������";
    default: return L"����������";
    }
}

wostream& operator<<(wostream& out, const Soldier& s) {
    out << L"ID: " << s.ID << endl;
    out << L"���: " << s.Name << endl;
    out << L"�������: " << s.Surname << endl;
    out << L"�������: " << s.Age << endl;
    out << L"������: " << Soldier::rankToString(s.RankID) << endl;
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
