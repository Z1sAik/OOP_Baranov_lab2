#pragma once
#include <iostream>
#include <string>
#include <fstream>

template <typename T>
T readNumber(T min, T max) {
    T x;
    while (true) {
        if (!(std::wcin >> x)) {
            std::wcin.clear();
            std::wcin.ignore(10000, L'\n');
            std::wcout << L"������! ������� ����� �� " << min << L" �� " << max << L"." << std::endl;
            continue;
        }
        std::wcin.ignore(10000, L'\n');
        if (x < min || x > max) {
            std::wcout << L"����� ��� ���������! ���������� �����." << std::endl;
            continue;
        }
        return x;
    }
}

class Squad;
void saveSquad(const Squad& squad);
void loadSquad(Squad& squad);