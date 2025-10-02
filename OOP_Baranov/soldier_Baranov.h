#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Soldier {
private:
    static int NextID;
    int ID;
    std::wstring Name;
    std::wstring Surname;
    int Age;
    int RankID;

public:

    Soldier() {
        ID = 0;
        Name = L"";
        Surname = L"";
        Age = 0;
        RankID = 0;
    }

    friend std::wostream& operator<<(std::wostream& out, const Soldier& s);
    friend std::wistream& operator>>(std::wistream& in, Soldier& s);
    friend std::wofstream& operator<<(std::wofstream& fout, const Soldier& s);
    friend std::wifstream& operator>>(std::wifstream& fin, Soldier& s);
    static std::wstring rankToString(int id);
};