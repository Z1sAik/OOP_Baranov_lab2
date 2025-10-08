#pragma once
#include <vector>
#include <memory>
#include "soldier_Baranov.h"

class Squad {
private:
    std::vector<std::shared_ptr<Soldier>> Soldiers;

public:
    void input();
    void showAll() const;
    void clear();
    void updateNextIDAfterLoad();

    std::vector<std::shared_ptr<Soldier>>& getSoldiers() { return Soldiers; }
    const std::vector<std::shared_ptr<Soldier>>& getSoldiers() const { return Soldiers; }

};
