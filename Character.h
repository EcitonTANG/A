#ifndef IT_2003_2004_L1_CHARACTER_H
#define IT_2003_2004_L1_CHARACTER_H
#include <iostream>
using namespace std;
#include <string>
#include <ctime>
#include "Item.h"

class Character {
public:
    Character();
    void initialize(string name);
    void levelUp();
    int getHP();
    int getAtk();
    string showStats();

    void Battle();
    void enemyBattle();
    int showEnemyHp(int enemyhp);
    int showHp(int enemyattack);
    int rest();
    string thought();

    const Item &getItem() const;

    void setItem(const Item &item);
    void gainExp(int exp);

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
