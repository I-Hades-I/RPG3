#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Inventory.h"
#include "Items.h"
using namespace std;


Inventory::Inventory(int space) : head("null", "null", "Head", "null", 0, 0, 0, 0), chest("null", "null", "Chest", "null", 0, 0, 0, 0), legs("null", "null", "Legs", "null", 0, 0, 0, 0), rhand("null", "null", "Right Hand", "null", 0, 0, 0, 0), lhand("null", "null", "Left Hand", "null", 0, 0, 0, 0), space(space) {}

void Inventory::init_body() {
    body.push_back(head);
    body.push_back(chest);
    body.push_back(legs);
    body.push_back(rhand);
    body.push_back(lhand);
}



void Inventory::equip(int& health, int& maxhp) {
    printf("\033c");
    print_inventory();
    printequip();
    cout << "what do you want to equip? (0 to close)\n";
    int y;
    cin >> y;
    if (y <= 0) {goto close;}
    int x;
    x = y -1;
    for (int i = 0; i < body.size(); i++) {
        if (body[i].slot == Equipment[x]->slot) {
            if (body[i].name == "null") {
                body[i].name = Equipment[x]->name;
                body[i].rarity = Equipment[x]->rarity;
                body[i].slot = Equipment[x]->slot;
                body[i].Class = Equipment[x]->Class;
                body[i].health = Equipment[x]->health;
                body[i].attack = Equipment[x]->attack;
                body[i].defense = Equipment[x]->defense;
                body[i].mana = Equipment[x]->mana;
                Equipment.erase(Equipment.begin() + x);
                health += body[i].health;
                maxhp += body[i].health;
                break;
            }
            else {
                health -= body[i].health;
                maxhp -= body[i].health;
                Equipment.emplace_back(new equipment(body[i].name, body[i].rarity, body[i].slot, body[i].Class, body[i].health, body[i].attack, body[i].defense, body[i].mana, 0));
                body[i].name = Equipment[x]->name;
                body[i].rarity = Equipment[x]->rarity;
                body[i].slot = Equipment[x]->slot;
                body[i].Class = Equipment[x]->Class;
                body[i].health = Equipment[x]->health;
                body[i].attack = Equipment[x]->attack;
                body[i].defense = Equipment[x]->defense;
                body[i].mana = Equipment[x]->mana;
                Equipment.erase(Equipment.begin() + x);
                health += body[i].health;
                maxhp += body[i].health;
                break;
            }
        }
    }
    close:
        y = 0;
}

void Inventory::unequip(int& health, int& maxhp) {
    printf("\033c");
    print_inventory();
    printequip();
    cout << "what would you like to unequip? (0 to close)\n";
    int in;
    cin >> in;
    if (in <= 0 || in > 5) {goto close;}
    int i;
    i = in-1;
    if (body[i].name != "null") {
        health -= body[i].health;
        maxhp -= body[i].health;
        Equipment.emplace_back(new equipment(body[i].name, body[i].rarity, body[i].slot, body[i].Class, body[i].health, body[i].attack, body[i].defense, body[i].mana, 0));
        body[i].name = "null";
        body[i].rarity = "null";
        body[i].Class = "null";
        body[i].health = 0;
        body[i].attack = 0;
        body[i].defense = 0;
        body[i].mana = 0;
    }
    close:
        in = 0;
}

void Inventory::print_inventory() {
    cout << "Inventory:\n";
    
    for (int i = 0; i < Equipment.size(); i++) {
        cout << i+1 << ". ";
        Equipment[i]->printstats();
    }
    
    
    for (int x = 0; x < Materials.size(); x++) {
        if (Materials[x]->amount > 0) {
            cout << Materials[x]->name << "(x" << Materials[x]->amount << ")\n";
        }
    }
    
    cout << "\n";
}

void Inventory::printequip() {
    cout << "Equipment:\n";
    for (int i = 0; i < body.size(); i++) {
        cout << body[i].slot << ":\n";
        if (body[i].name == "null") {
            cout << "None:\n\n";
        }
        else {
            body[i].printstats();
        }
    }
}

void Inventory::crafting() {
    printf("\033c");
    int i;
    vector<equipment*>craftequip;
    vector<material*>craftmats;
    vector<equipment*>result;
    for (i = 0; i < Equipment.size(); i++) {
        int x;
        if (Equipment[i]->name == "wood sword") {
            for (x = 0; x < Materials.size(); x++) {
                if (Materials[x]->name == "Iron" && Materials[x]->amount > 0) {
                    craftequip.emplace_back(new equipment(Equipment[i]->name, Equipment[i]->rarity, Equipment[i]->slot, Equipment[i]->Class, Equipment[i]->health, Equipment[i]->attack, Equipment[i]->defense, Equipment[i]->mana, 0));
                    craftmats.emplace_back(new material(Materials[x]->name, Materials[x]->rarity, Materials[x]->amount));
                    craftequip.emplace_back(new equipment("Iron sword", "uncommon", "Right Hand", "Melee", 0, 15, 0, 0, 1));
                    craftmats.emplace_back(new material("Iron sword", "uncommon", 1));
                    Equipment.erase(Equipment.begin() + i);
                    Materials[x]->amount -= 1;
                    result.emplace_back(new equipment("Iron sword", "uncommon", "Right Hand", "Melee", 0, 15, 0, 0, 1));
                    break;
                }
            }
        }
        x = 0;
    }
    cout << "Possible crafts:\n";
    for (int y = 0; y < result.size(); y++) {
        cout << y+1 << ". ";
        result[y]->printstats();
    }
    cout << "What would you like to craft? (0 to close)\n";
    int z;
    cin >> z;
    if (z <= 0) {goto close;}
    for ( int q = 0; q < craftequip.size(); q++) {
        if (craftequip[q]->name == result[z-1]->name) {
            int start = q - craftequip[q]->rawmaterials;
            int range = q + 1;
            craftequip.erase(craftequip.begin() + start, craftequip.begin() + range);
        }
    }
    
    for (int idk = 0; idk < craftmats.size(); idk++) {
        if (craftmats[idk]->name == result[z-1]->name) {
            int start = idk - craftequip[idk]->rawmaterials;
            int range = idk + 1;
            craftmats.erase(craftmats.begin() + start, craftmats.begin() + range);
            break;
        }
    }
    Equipment.emplace_back(new equipment(result[z-1]->name, result[z-1]->rarity, result[z-1]->slot, result[z-1]->Class, result[z-1]->health, result[z-1]->attack, result[z-1]->defense, result[z-1]->mana, 0));
    close:
        int close_;
    
    for (int q = 0; q < craftequip.size(); q++) {
        Equipment.emplace_back(new equipment(craftequip[q]->name, craftequip[q]->rarity, craftequip[q]->slot, craftequip[q]->Class, craftequip[q]->health, craftequip[q]->attack, craftequip[q]->defense, craftequip[q]->mana, 0));
    }
    for (int z = 0; z < craftmats.size(); z++) {
        
        for (int ok = 0; ok < Materials.size(); ok++) {
            if (Materials[ok]->name == craftmats[z]->name) {
                Materials[ok]->amount = craftmats[z]->amount;
            }
        }
    }
    print_inventory();
    
}




//end
