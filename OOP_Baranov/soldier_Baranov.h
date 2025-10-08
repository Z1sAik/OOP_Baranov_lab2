#pragma once
#include <string>
#include <iostream>
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>

class Soldier_Baranov {
private:
    static int NextID;
    int ID;
    std::wstring Name;
    std::wstring Surname;
    int Age;
    int RankID;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int) {
        ar& ID;
        ar& Name;
        ar& Surname;
        ar& Age;
        ar& RankID;
    }

public:
    Soldier_Baranov() : ID(0), Name(L""), Surname(L""), Age(0), RankID(0) {}
    virtual ~Soldier_Baranov() {}

    virtual void input();
    virtual void output() const;
    static std::wstring rankToString(int id);

    int getID() const
    {
        return ID;
    }

    static void setNextID(int value)
    {
        NextID = value;
    }

    virtual std::wstring getType() const {
        return L"Солдат";
    }
};

