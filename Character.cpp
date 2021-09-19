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
    HP = 10;
    maxHP = 10;
    atk = 2;
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
        HP=maxHP;
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
