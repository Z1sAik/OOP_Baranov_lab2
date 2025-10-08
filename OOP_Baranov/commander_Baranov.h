#pragma once
#include "soldier_Baranov.h"


class Commander_Baranov : public Soldier_Baranov {
private:
    int Tasks;
    int Type;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int) {
        ar& boost::serialization::base_object<Soldier_Baranov>(*this);
        ar& Tasks;
        ar& Type;
    }

public:
    Commander_Baranov() : Tasks(0), Type(0) {}
    virtual ~Commander_Baranov() {}

    virtual void input() override;
    virtual void output() const override;
    virtual std::wstring getType() const override {
        return L"Командир";
    }
};

