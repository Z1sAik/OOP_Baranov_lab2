#pragma once
#include "soldier_Baranov.h"
#include <boost/serialization/export.hpp>

class Commander : public Soldier {
private:
    int Awards;
    int Subordinates;
    int Type;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int) {
        ar& boost::serialization::base_object<Soldier>(*this);
        ar& Awards& Subordinates& Type;
    }

public:
    Commander() : Awards(0), Subordinates(0), Type(0) {}
    virtual ~Commander() {}

    virtual void input() override;
    virtual void output() const override;
};


