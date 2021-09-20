#include "Character.h"

Character::Character() {
    name = "Player";
    HP = 0;
    maxHP = 0;
    atk = 0;
    exp = 0;
    level = 0;
}

void Character::initialize(string name){
    this->name = name;//keyword "this", helps to override variables with same naming;
    HP = 20;
    maxHP = 10;
    atk = 5;
    exp = 0;
    level = 1;

};

void Character::gainExp(int expAdd){
    exp = exp + expAdd;
    //setExp(getExp()+expAdd);
    levelUp();
}

void Character::levelUp(){
    //exp->level->add stats;
    while (exp >= level*10){
        level++;
        exp=0;
        maxHP = maxHP +5;
        atk = atk+1;
    }
}

string Character::showStats(){

    string string1= "Name: "+name+"\n"+"HP: "+ to_string(HP)+"/"+ to_string(maxHP)+
            "\n"+ "Atk: "+ to_string(atk)+"\n"+"exp: "+to_string(exp)+"\n"+"level: "+to_string(level)+"\n"
            +"Item: "+ item.getName()+"\n";

    return string1;

}

int Character::getHP() {
    return HP;
}

int Character::getAtk() {
    return atk;
}
//In your Inventory you can store only best 3 items (they must be automatically equipped).
//more atk = better item
const Item &Character::getItem() const {
    return item;
}

void Character::setItem(const Item &item) {
    Character::item = item;
}

void Character::Battle()
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

void Character::enemyBattle() {
    int enemyhp = 15, enemyattack = 4;
    int hitEnemy;

    do {
        cout << "\nHit enemy?\n Yes = 1\n No = 2\n";
        cin >> hitEnemy;
        if (hitEnemy == 1)
        {
            enemyhp = showEnemyHp(enemyhp);
            HP = showHp(enemyattack);
            cout << "\nYou hit the enemy.\n";
            cout << "The enemy now has " << enemyhp << "HP left.\n\n";
            if(enemyhp <= 0)
            {
                cout << "You won!\n";
            }
            else if(enemyhp > 0)
            {
                cout << "The enemy hit you back.\n";
                cout << "You now have " << HP << "HP left.\n\n";
            }
        }
        else if(hitEnemy == 2)
        {
            HP = showHp(enemyattack);
            cout << "You chose not to hit the enemy so he hit you instead\n";
            cout << "You now have " << HP << "HP left.\n\n";
        }
        else
        {
            cout << "That is not a valid choice.\n\n";
            return enemyBattle();
        }

    }while(HP > 0 && enemyhp > 0);
}

int Character::showEnemyHp(int enemyhp)
{
    enemyhp = enemyhp - atk;
    return enemyhp;
}

int Character::showHp(int enemyattack)
{
    HP = HP - enemyattack;
    return HP;
}

int Character::rest() {
    HP = maxHP;
    return HP;
}

