#pragma once
#include "soldier_Baranov.h"


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
    virtual void output() const override;
    virtual std::wstring getType() const override {
        return L"Командир";
    }
};

