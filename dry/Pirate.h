
#pragma once

#include <iostream>

using std::string;

class Pirate {
private:
    string name;
    unsigned int bounty;


public:
    Pirate() = default;
    Pirate(const string& name , unsigned int bounty);

    ~Pirate() = default;

    void setName(const string& name);
    void setBounty (const unsigned int& bounty);


    string getName();
    unsigned int getBounty();

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
