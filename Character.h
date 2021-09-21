#ifndef IT_2003_2004_L1_CHARACTER_H
#define IT_2003_2004_L1_CHARACTER_H
#include <iostream>
using namespace std;
#include <string>
#include <ctime>
#include "Item.h"

class Character {
public:
    Character(); //Constructor for the Character class
    void initialize(string name); //The initialization function, it initializes the player
    void levelUp(); //Raises the level of the hero.
    int getHP(); //Returns the current health
    int getAtk(); //Returns the current attack
    string showStats(); //Returns the current characteristics

    void Battle(); //The battle function starts where the player chooses whether to attack the enemy or not
    void enemyBattle(); //The battle function, here the battle itself unfolds
    int showEnemyHp(int enemyhp); //The function of fixing the player's strike
    int showHp(int enemyattack); //The function of fixing the enemy's strike
    int rest(); //Rest function, make the HP variable level to MaxHP
    void thought(); //This function gives out random thoughts of the player during the rest

    const Item &getItem() const; //Adding experience to the current one
    void setItem(const Item &item); //Changes the current weapon to a new one
	
    void gainExp(int exp); //Adding experience to the current one

private:
    string name;
    int HP;
    int maxHP;
    int atk;
    int exp;
    int level;
    Item item;
};


#endif //IT_2003_2004_L1_CHARACTER_H
