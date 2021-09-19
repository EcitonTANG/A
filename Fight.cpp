#include <iostream>
#include "Fight.h"

using namespace std;

int Fight::Battle()
{
    int battle;
    cout << "\nYou see an enemy in the distance. Attack enemy?\n Yes = 1\n No = 2\n";
    cin >> battle;
    if(battle==1)
    {
        enemyBattle();
    }
    else if(battle==2)
    {
        cout << "You chose to not attack the enemy.\n";
    }
    else
    {
        cout << "That is not a valid choice.\n\n";
        return Battle();
    }

}

void Fight::enemyBattle() {
    int enemyhp = 15, enemyattack = 5;
    int hitGoblin;
    int hp = character.getHP();
    int attack = character.getAtk();

    do {
        cout << "\nHit enemy?\n Yes = 1\n No = 2\n";
        cin >> hitGoblin;
        if (hitGoblin == 1)
        {
            enemyhp = showEnemyHp(enemyhp, attack);
            hp = showHp(hp, enemyattack);
            cout << "\nYou hit the enemy.\n";
            cout << "The enemy now has " << enemyhp << "HP left.\n\n";
            if(enemyhp <= 0)
            {
                cout << "You won!\n";
            }
            else if(enemyhp > 0)
            {
                cout << "The enemy hit you back.\n";
                cout << "You now have " << hp << "HP left.\n\n";
            }
        }
        else if(hitGoblin == 2)
        {
            cout << "You chose not to hit the enemy so he hit you instead\n";
            cout << "You now have " << showHp(hp, enemyattack) << "HP left.\n\n";
        }
        else
        {
            cout << "That is not a valid choice.\n\n";
            return enemyBattle();
        }

    }while(hp > 0 && enemyhp > 0);
}

int Fight::showEnemyHp(int enemyhp, int attack)
{
    attack = character.getAtk();
    enemyhp = enemyhp - attack;
    return enemyhp;
}

int Fight::showHp(int hp, int enemyattack)
{
    hp = character.getHP() - enemyattack;
    return hp;
}