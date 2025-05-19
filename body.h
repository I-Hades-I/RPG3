#ifndef BODY
#define BODY
#include "Items.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Body : public Items {
    public:
        string rarity;
        int health;
        int attack;
        int defense;
        int mana;
        string slot;
        string Class;

        Body(string name, string rarity, string slot, string Class, int health, int attack, int defense, int mana);
        void printstats();
};


#endif
