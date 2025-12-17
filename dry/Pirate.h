#pragma once

#include <iostream>

using std::string;

enum DEVIL_FRUIT {
    GUM_GUM_FRUIT,
    SMOKE_SMOKE_FRUIT,
    FLAME_FLAME_FRUIT,
    RUMBLE_RUMBLE_FRUIT,
    STRING_STRING_FRUIT,
    ICE_ICE_FRUIT,
    NONE
};

class Pirate {
private:
    string name;
    unsigned int bounty;
    DEVIL_FRUIT devilFruit;

public:
    Pirate() = default;
    Pirate(const string& name , unsigned int bounty,DEVIL_FRUIT devilFruit = DEVIL_FRUIT::NONE);


    ~Pirate() = default;

    void setName(const string& name);
    void setBounty (const unsigned int& bounty);

    void setDevilFruit(DEVIL_FRUIT devilFruit);

    string getName();
    unsigned int getBounty();
    DEVIL_FRUIT getDevilFruit();

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
