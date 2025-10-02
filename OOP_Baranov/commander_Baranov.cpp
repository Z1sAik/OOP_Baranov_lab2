#include "commander_Baranov.h"
#include "function_Baranov.h"
#include <iostream>

using namespace std;
 
wistream& operator>>(wistream& in, Commander& c) {
    wcout << L"Добавляем командира:" << endl;
    //// ЭТО все неправильно исправить надо 
    wcout << L"Количество подчинённых: ";
    c.Subordinates = readNumber<int>(0, 100);

    wcout << L"Количество наград: ";
    c.Numberofawards = readNumber<int>(0, 100);

    return in;
}

wostream& operator<<(wostream& out, const Commander& c) {
    out << L"--- Командир ---" << endl;
    out << static_cast<const Soldier&>(c);
    out << L"Звание: " << Commander::rankToString(c.getRankID()) << endl;
    out << L"Подчинённых: " << c.Subordinates << endl;
    out << L"Награды: " << c.Numberofawards << endl;
    return out;
}

wofstream& operator<<(wofstream& fout, const Commander& c) {
    fout << L"Commander" << endl;
    fout << static_cast<const Soldier&>(c);
    fout << c.getRankID() << endl;
    fout << c.Subordinates << endl;
    fout << c.Numberofawards << endl;
    return fout;
}

wifstream& operator>>(wifstream& fin, Commander& c) {
    fin >> static_cast<Soldier&>(c);
    int rank;
    fin >> rank;
    c.setRankID(rank);
    fin >> c.Subordinates;
    fin >> c.Numberofawards;
    fin.ignore(10000, L'\n');
    return fin;
}

