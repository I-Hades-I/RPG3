#include "Character.h"
#include "Inventory.h"
#include "Items.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

Character* charcreation();
Character* enemycreation();
void open_inventory(Character* player);
void combat(Character* player, Character* enemy);

int main() {
    Character* player = charcreation();
    player->init_inventory();
    player->init_sack();
    player->inventory.init_body();
    player->init_spells();
    printf("\033c");
    
    while (1) {
        printf("\033c");
        player->printstats();
        cout << "what would you like to do?\n";
        cout <<"1. Explore the world\n2.open Inventory\n3.view spells\n";
        int input;
        cin >> input;
        Character* goblin = new Goblin(1);
        goblin->init_spells();
        switch (input) {
            case 1:
                combat(player, goblin);
                break;
            case 2:
                open_inventory(player);
                break;
            
            default:
                break;
        }
    }
}


Character* charcreation() {
    cout << "Enter your name: ";
    string name;
    getline(cin, name);
    cout << "\nChoose a class:\n1. Melee\n2.Mage\n";
    int gett;
    cin >> gett;
    switch (gett) {
        case 1:
             return new Melee(name);
            break;
        case 2:
            return new Mage(name);
            break;
        default :
            cout << "invalid";
            return new Melee(name);
    }
}

void open_inventory(Character* player) {
    while (1) {
        printf("\033c");
        player->inventory.print_inventory();
        player->inventory.printequip();
        cout << "What would you like to do?\n";
        bool z = 0;
        if(player->inventory.Equipment.size() > 0) {z = 1;}
        bool y = 0;
        for (int i = 0; i < player->inventory.body.size(); i++) {
            if (player->inventory.body[i].name != "null") {
                y = 1;
                break;
            }
        }
        if (z == 1 && y == 1) {
            cout << "1. equip item\n2. unequip item\n3. craft\n4. close inventory";
            int input;
            cin >> input;
            switch (input) {
                case 1:
                    player->inventory.equip(player->health, player->maxhp);
                    break;
                case 2:
                    player->inventory.unequip(player->health, player->maxhp);
                    break;
                case 3:
                    player->inventory.crafting();
                    break;
                case 4:
                    goto close;
            }
        }
        if (z == 1 && y == 0) {
            cout << "1. equip item\n2. craft\n3. close inventory";
            int input;
            cin >> input;
            switch (input) {
                case 1:
                    player->inventory.equip(player->health, player->maxhp);
                    break;
                case 2:
                    player->inventory.crafting();
                    break;
                case 3:
                    goto close;
            }
        }
        if (z == 0 && y == 1) {
            cout << "1. unequip item\n2. craft\n3. close inventory";
            int input;
            cin >> input;
            switch (input) {
                case 1:
                    player->inventory.unequip(player->health, player->maxhp);
                    break;
                case 2:
                    player->inventory.crafting();
                    break;
                case 3:
                    goto close;
            }
        }
        if (z == 0 && y == 0) {
            cout << "1. craft\n2. close inventory";
            int input;
            cin >> input;
            switch (input) {
                case 1:
                    player->inventory.crafting();
                    break;
                case 2:
                    goto close;
            }
        }
    }
    close:
        int bye;
}

void combat(Character* player, Character* enemy) {
    cout << "You encounter a " << enemy->name << "\n";
    do {
        printf("\033c");
        player->printstats();
        enemy->printstats();
        cout << "options:\n1. attack\n2.defend\n3. Health flask\n4. Mana flask\n";
        int choice;
        cin >> choice;
        vector<string>aspell;
        srand(time(0));
        int min = 1;
        int max = 2;
        int randomNumber = (rand() % (max - min + 1)) + min;
        switch (choice) {
            case 1:
                if (randomNumber == 2) {
                    enemy->takedamage(player->usespell(choice), enemy->usespell(randomNumber)); //p attack, e defend
                    
                }
                else {
                    enemy->takedamage(player->usespell(choice), enemy->defense);
                    player->takedamage(enemy->usespell(1), player->getdefense());
                }
                break;
            case 2:
                if (randomNumber == 1) {
                    player->takedamage(enemy->usespell(randomNumber), player->usespell(choice));
                }
                break;
                
        }        
    }while (player->health > 0 && enemy->health > 0);
    
    if (player->health <= 0) {
        cout << "you lose\n";
        //exit code
    }
    if (enemy->health <= 0) {
        player->getexp(enemy->Exp);
        material* mat = enemy->loot_table();
        for (int i = 0; i < player->inventory.Materials.size(); i++) {
            if (player->inventory.Materials[i]->name == mat->name) {
                player->inventory.Materials[i]->amount += mat->amount;
                break;
            }
        }
    }
}






//end
