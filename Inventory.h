#ifndef INVENTORY
#define INVENTORY
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Items.h"
#include "body.h"
using namespace std;


class Inventory {
    public:
        Body head;
        Body chest;
        Body legs;
        Body rhand;
        Body lhand;
        
        int space;
        
        vector<Body>body;
        vector<equipment*>Equipment;
        vector<material*>Materials;
        
        Inventory(int space);
        
        void init_body();
        void equip(int& health, int& maxhp);
        void unequip(int& health, int& maxhp);
        void print_inventory();
        void printequip();
        void crafting();
};

#endif
