#pragma once
#include <vector>
#include <memory>
#include "soldier_Baranov.h"

class Squad {
private:
    std::vector<std::shared_ptr<Soldier>> Soldiers;

public:
    void addSoldierOnly();
    void addCommanderOnly();
    void showAll() const;

    std::vector<std::shared_ptr<Soldier>>& getSoldiers() { return Soldiers; }
    const std::vector<std::shared_ptr<Soldier>>& getSoldiers() const { return Soldiers; }

    void clear();

    void updateNextIDAfterLoad();
};
