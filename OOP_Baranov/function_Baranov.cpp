#include "function_Baranov.h"
#include "squad_Baranov.h"
#include <iostream>
#include <string>
#include <fstream>
#include <codecvt>

using namespace std;

void saveSquad(const Squad& squad) {
    wstring filename;
    wcout << L"������� ��� ����� ��� ����������: ";
    getline(wcin >> ws, filename);
    filename += L".txt";

    wofstream fout(filename, ios::out);
    fout.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
    if (!fout.is_open()) {
        wcout << L"������ ��� �������� ����� ��� ������!" << endl;
        return;
    }

    squad.writeToFile(fout);
    fout.close();

    wcout << L"������ ��������� � ����: " << filename << endl;
}

void loadSquad(Squad& squad) {
    wstring filename;
    wcout << L"������� ��� ����� ��� ��������: ";
    getline(wcin >> ws, filename);

    if (filename.find(L".txt") == wstring::npos) {
        filename += L".txt";
    }

    wifstream fin(filename);
    fin.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
    if (!fin.is_open()) {
        wcout << L"���� " << filename << L" �� ������!" << endl;
        return;
    }

    squad.clear();

    squad.readFromFile(fin);
    fin.close();

    wcout << L"������ ��������� �� �����: " << filename << endl;
}
