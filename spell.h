#ifndef SPELL
#define SPELL
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class spell {
    public:
        string name;
        string type;
        bool has;
        int mana_cost;
        int health;
        int attack;
        int defense;
        int level;
        spell(string name, string type, bool has, int mana_cost, int level);
    
    virtual int effect(int input);
};

class slash : public spell {
    public:
        slash(bool has);
        int effect(int input);
};

class block : public spell {
    public: 
        block(bool has);
        int effect(int input);
};

class magic_bullet : public spell {
    public:
        magic_bullet(bool has);
        int effect(int input);
};

class magic_shield : public spell {
    public:
        magic_shield(bool has);
        int effect(int input);
};




#endif
