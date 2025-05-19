#ifndef CHARACTER
#define CHARACTER
#include "Inventory.h"
#include "Items.h"
#include "spell.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Character {
    public:
        Inventory inventory;
        string name;
        int level;
        int maxhp;
        int health;
        int attack;
        int defense;
        int mana;
        int Exp;
        
        vector<spell*>Spell;
        
        Character(string name, int level, int Exp, int maxhealth, int attack, int defense, int mana);
        
        virtual void printstats();
        virtual int getdefense();
        virtual int getattack();
        virtual int usespell(int choice);
        void getexp(int exp);
        virtual void levelup();
        int spell_cast(int i);
        virtual void init_inventory();
        virtual void init_sack();
        virtual void init_spells();
        void takedamage(int Attack, int Defense);
        virtual material* loot_table();
};

class Melee : public Character {
    public: 
        
        string Class = "Melee";
        
        Melee(string name);
        void init_inventory();
        void init_spells();
        void levelup();
};

class Mage : public Character {
    public:
        string Class = "Mage";
        Mage(string name);
        void init_inventory();
        void init_spells();
        void levelup();
};

class Enemy : public Character{
    public:
        Enemy(string name, int level, int Exp, int maxhealth, int attack, int defense, int mana);
        int usespell(int choice);
};


class Goblin : public Enemy {
    public:
        Goblin(int plevel);
        void init_spells();
        material* loot_table();
};


#endif
