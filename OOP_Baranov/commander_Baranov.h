#pragma once
#include "soldier_Baranov.h"
#include <vector>
#include <memory>

class Commander : public Soldier {
private:
    int Tasks;
    int Type;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int) {
        ar& boost::serialization::base_object<Soldier>(*this);
        ar& Tasks& Type;
    }

public:
    Commander() : Tasks(0), Type(0) {}
    virtual ~Commander() {}

    virtual void input() override;
    void output(const std::vector<std::shared_ptr<Soldier>>& squad) const;
};
