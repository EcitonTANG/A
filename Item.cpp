#include "Item.h"


Item::Item() {
}

Item * Item::createItem(string name, int atk){
    this->name= name;
    this->atk= atk;
    return this;
}

const string &Item::getName() const {
    return name;
}

void Item::setName(const string &name) {
    Item::name = name;
}

int Item::getAtk() const {
    return atk;
}

void Item::setAtk(int atk) {
    Item::atk = atk;
}

int Item::getHp() const {
    return HP;
}

void Item::setHp(int hp) {
    HP = hp;
}
