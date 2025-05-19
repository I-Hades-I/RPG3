#include "spell.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

spell::spell(string name, string type, bool has, int mana_cost, int level) : name(name), type(type), has(has), mana_cost(mana_cost), level(level) {}

int spell::effect(int input) {
    input += 1;
    return input;
}

slash::slash(bool has) : spell("slash", "damage", has, 0, 1) {}

int slash::effect(int input) {
    int Attack;
    Attack = (level*4) + (input*1.3);
    return Attack;
}

block::block(bool has) : spell("block", "defense", has, 0, 1) {}

int block::effect(int input) {
    int Defense = (level*3) + (input*1.4);
    return Defense;
}



magic_bullet::magic_bullet(bool has) : spell("magic bullet", "damage", has, 3, 1) {}

int magic_bullet::effect(int input) {
    int Attack;
    Attack = (level * input);
    return Attack;
}

magic_shield::magic_shield(bool has) : spell("magic shield", "defense", has, 4, 1) {}

int magic_shield::effect(int input) {
    int Defense = (level*3) + (input*1.4);
    return Defense;
}
