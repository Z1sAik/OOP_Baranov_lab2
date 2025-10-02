#pragma once
#include <vector>
#include <fstream>
#include "soldier_Baranov.h"

class Squad {
private:
    std::vector<Soldier*> Soldiers;

public:
    ~Squad() {
        clear();
    }

    void addSoldier();
    void showAll() const;
    void readFromFile(std::wifstream& fin);
    void writeToFile(std::wofstream& fout) const;
    void clear();
};
