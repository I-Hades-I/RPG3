#ifndef ITEMS
#define ITEMS
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Items {
    public:
        string name;
        string rarity;
        Items(string name, string rarity);
};

class equipment : public Items {
    public:
        string slot;
        int health;
        int attack;
        int defense;
        int mana;
        int rawmaterials;
        string Class;
        equipment(string name, string rarity, string slot, string Class, int health, int attack, int defense, int mana, int raw_materials);
        
        void printstats();
};

class material : public Items {
    public:
        int amount;
        material(string name, string rarity, int amount);
};


#endif
