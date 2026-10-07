#include "archer.h"
#include <iostream>
#include "character.h"

using namespace std;

Archer::Archer(string name):Character(name,'a')
{
    _arrows=5;
    _agility=1;
    _store.setStore(2);
    _equiped=_store.getFist();
}

Archer::Archer(string name, int health, int accuracy, int protection, int power, int level, int arrows, int agility, int xp, int money):Character(name,health,accuracy,protection,power,level,xp,money){
    _arrows=arrows;
    _agility=agility;
    _store.setStore(2);
    _equiped=_store.getFist();
}
Archer::Archer(const Archer &A):Character(A){
    _arrows=A._arrows;
    _agility=A._agility;
}
void Archer::calcAttack(){
    _attack=(_power*_level)+(((*_equiped)->getWeaponpower()*_arrows)/15);
    _defence=(_protection*_level)+(2*_agility);
}

void Archer::equipWeapon(int pos){
    if(pos==-1){
        _equiped=_store.getFist();
    }
    else{
        cout<<"changing weapon"<<endl;
        _equiped=&(*_inventory.getWeDirect())[pos];
    }

}

void Archer::statsXp(){
    int power=2+2*(_level-1);
    int protection=20+(_level-1)+3*((_level-1)/7);
    int agility=_level-(_level/2);
    if (_level>10){
        agility=agility+((_level-10)/2);
    }

    if(_agility>=agility&&_protection>=protection&&_power>=power){
        _inventory.addMoney(2);
    }
    else{
        if(_power<power){
            _power=power;
        }
        if(_protection<protection){
            _protection=protection;
        }
        if(_agility<agility){
            _agility=agility;
        }
    }
}

void Archer::display(){
    cout<<endl<<"Agility: "<<_agility<<endl;
    cout<<endl<<"Number of arrows: "<<_arrows<<endl;
    cout<<endl<<"Weapon equiped:"<<endl;
    (*_equiped)->display();
    this->calcAttack();
    cout<<endl<<"Combat:"<<endl<<"   Attack: "<<_attack<<endl<<"   Defence: "<<_defence<<endl;
}
