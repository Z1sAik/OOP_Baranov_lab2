#pragma once
#include <vector>
#include <memory>
#include "soldier_Baranov.h"

class Squad_Baranov {
private:
    std::vector<std::shared_ptr<Soldier_Baranov>> Soldiers;

public:
    void input();
    void showAll() const;
    void clear();
    void updateNextIDAfterLoad();
    void saveToFile() const;
    void loadFromFile();

    std::vector<std::shared_ptr<Soldier_Baranov>>& getSoldiers() { return Soldiers; }
    const std::vector<std::shared_ptr<Soldier_Baranov>>& getSoldiers() const { return Soldiers; }

};
