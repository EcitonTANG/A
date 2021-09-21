#include "Character.h"

//Constructor for the Character class
Character::Character() {
    name = "Player";
    HP = 0;
    maxHP = 0;
    atk = 0;
    exp = 0;
    level = 0;
}

//The initialization function, it initializes the player
void Character::initialize(string name){
    this->name = name;
    HP = 20;
    maxHP = 20;
    atk = 5;
    exp = 0;
    level = 1;
};

//Adding experience to the current one
void Character::gainExp(int expAdd){
    exp = exp + expAdd;
    levelUp();
}

//Raises the level of the hero
void Character::levelUp(){
    while (exp >= level*10){
        level++;
        exp=0;
        maxHP = maxHP +5;
        atk = atk+1;
    }
}

//Returns the current characteristics
string Character::showStats(){

    string string1= "Name: "+name+"\n"+"HP: "+ to_string(HP)+"/"+ to_string(maxHP)+
            "\n"+ "Atk: "+ to_string(atk)+"\n"+"exp: "+to_string(exp)+"\n"+"level: "+to_string(level)+"\n"
            +"Item: "+ item.getName()+"\n";

    return string1;

}

//Returns the current health
int Character::getHP() {
    return HP;
}

//Returns the current attack
int Character::getAtk() {
    return atk;
}

//Returns the current item
const Item &Character::getItem() const {
    return item;
}

//Changes the current weapon to a new one
void Character::setItem(const Item &item) {
    Character::item = item;
}

//The battle function starts where the player chooses whether to attack the enemy or not
void Character::Battle()
{
    int battle;
    cout << "\nYou have stumbled upon an enemy from a distance. Attack the enemy?\n Yes = 1\n No = 2\n";
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
        cout << "Error!! Not a valid choice.\n\n";
        return Battle();
    }

}

//The battle function, here the battle itself unfolds
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

//The function of fixing the player's strike
int Character::showEnemyHp(int enemyhp)
{
    enemyhp = enemyhp - atk;
    return enemyhp;
}

//The function of fixing the enemy's strike
int Character::showHp(int enemyattack)
{
    HP = HP - enemyattack;
    return HP;
}

//Rest function, make the HP variable level to MaxHP
int Character::rest() {
    HP = maxHP;
    return HP;
}

//This function gives out random thoughts of the player during the rest
void Character::thought() {
    const int MAX = 7;
    int random;
    string thoughts[MAX] = {
                             "I want to eat something delicious",
                             "I am so tired of this",
                             "The enemy was strong, I almost died",
                             "I hope I will be lucky further",
                             "I need to get better weapon as soon as possible",
                             "I hope no one will attack during my rest",
                             "The more I look at the bonfire the more I want to burn all these places"
                            };

    srand(time(0));

    random = rand()%MAX;
    string ans = thoughts[random];
    cout<<ans<<endl;
}