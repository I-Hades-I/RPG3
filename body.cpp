#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "body.h"
#include "Items.h"
using namespace std;

Body::Body(string name, string rarity, string slot, string Class, int health, int attack, int defense, int mana) : Items(name, rarity), slot(slot), Class(Class), health(health), attack(attack), defense(defense), mana(mana) {}
void Body::printstats() {
    cout << name << " | rarity: " << rarity;
    if (health > 0) { cout << " | Health: " << health; }
    if (attack > 0) { cout << " | Attack: " << attack; }
    if (defense > 0) { cout << " | Defense: " << defense; }
    if (mana > 0) { cout << " | Mana: " << mana; }
    cout << " |\n";
}
