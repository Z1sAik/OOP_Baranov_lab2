#pragma once
#include "soldier_Baranov.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Commander : public Soldier {
private:
    
    int Subordinates; // подчиненные
    int Numberofawards; // награды
	//Сделать как в первом примере сделать выбор типо командир взвода, начальник смены и т.д.
public:
    Commander() {
        Soldier(); 
        Numberofawards = 0;
        Subordinates = 0;
    }
     
    friend std::wistream& operator>>(std::wistream& in, Commander& c);
    friend std::wostream& operator<<(std::wostream& out, const Commander& c);
    friend std::wofstream& operator<<(std::wofstream& fout, const Commander& c);
    friend std::wifstream& operator>>(std::wifstream& fin, Commander& c);
    static std::wstring rankToString(int id);
};