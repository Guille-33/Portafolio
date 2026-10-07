#include <iostream>
#include "character.h"
#include <string>
#include "inventory.h"


using namespace std;

Character::Character(string name,int i)
{
    _name=name;
    _level=1;
    _health=100;
    _power=1;
    _protection=15;
    _xp=0;
    int lB = 1;
    int uB = 12;
    srand(time(NULL));
    _accuracy=lB+rand()%(uB-lB+1);
    _inventory.setMoney(0);
}

Character::Character(string name, char a)
{
    _name=name;
    _level=1;
    _health=100;
    _power=1;
    _protection=20;
    _xp=0;
    int lB = 1;
    int uB = 12;
    srand(time(NULL));
    _accuracy=lB+rand()%(uB-lB+1);
    _inventory.setMoney(0);
}

Character::Character(string name, string mg)
{
    _name=name;
    _level=1;
    _health=100;
    _power=50;
    _protection=50;
    _xp=0;
    int lB = 1;
    int uB = 12;
    srand(time(NULL));
    _accuracy=lB+rand()%(uB-lB+1);
    _inventory.setMoney(0);
}


Character::Character(string name, int health, int accuary, int protection, int power, int level, int xp, int money){
    _health=health;
    _accuracy=accuary;
    _protection=protection;
    _power=power;
    _name=name;
    _level=level;
    _xp=xp;
    _inventory.setMoney(money);
}
Character::Character(const Character &C){
    _health=C._health;
    _accuracy=C._accuracy;
    _protection=C._protection;
    _power=C._power;
    _name=C._name;
    _inventory=C._inventory;
    _level=C._level;
    _xp=C._xp;
}

void Character::setAccuary(int accuracy){
    _accuracy=accuracy;
}
void Character::setHealth(int health){
    _health=health;
}
void Character::setPower(int power){
    _power=power;
}
void Character::setProtection(int protection){
    _protection=protection;
}
void Character::setLevel(int level){
    _level=level;
}
void Character::display(){
    cout<<_name<<"     level: "<<_level<<endl<<"-------------------------------------------"<<endl;
    cout<<"health: "<<_health<<endl;
    cout<<endl<<"accuracy: "<<_accuracy<<endl;
    cout<<endl<<"protection: "<<_protection<<endl;
    cout<<endl<<"power: "<<_power<<endl;
    this->display();
    _inventory.display();
}
int Character::getAccuracy(){
    return _accuracy;
}
int Character::getHealth(){
    return _health;
}
int Character::getProtection(){
    return _protection;
}
int Character::getPower(){
    return _power;
}
int Character::getLevel(){
    return _level;
}
void Character::addXp(int xp){
    _xp=_xp+xp;
    while(_xp>=20){
        int lB = 0;
        int uB = 12;
        srand(time(NULL));
        int accuracy=lB+rand()%(uB-lB+1);
        this->setAccuary(accuracy);
        _level=_level+1;
        _xp=_xp-20;
        if(_level<15){
            this->statsXp();
        }
        else{
            _level=15;
        }
    }
}
