#include "Items.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

Items::Items(string name, string rarity) : name(name), rarity(rarity) {}

equipment::equipment(string name, string rarity, string slot, string Class, int health, int attack, int defense, int mana, int raw_materials) : Items(name, rarity), slot(slot), health(health), attack(attack), defense(defense), mana(mana), rawmaterials(raw_materials) {}

void equipment::printstats() {
    cout << name << " | rarity: " << rarity;
    if (health > 0) { cout << " | Health: " << health; }
    if (attack > 0) { cout << " | Attack: " << attack; }
    if (defense > 0) { cout << " | Defense: " << defense; }
    if (mana > 0) { cout << " | Mana: " << mana; }
    cout << " |\n";
}

material::material(string name, string rarity, int amount) : Items(name, rarity), amount(amount) {}
