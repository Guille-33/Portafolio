#include "warrior.h"
#include <iostream>
#include "character.h"
#include "potions.h"
#include "weapon.h"
using namespace std;

Warrior::Warrior(string name):Character(name,1)
{
    _strength=1;
    _shield=0;
    _store.setStore(1);
    _equiped.push_back(_store.getFist());
    _equiped.push_back(_store.getFist());
}

Warrior::Warrior(string name, int health, int accuracy, int protection, int power, int level, int shield, int strength, int xp, int money):Character(name,health,accuracy,protection,power,level,xp,money){
    _shield=shield;
    _strength=strength;
    _store.setStore(1);
    _equiped.push_back(_store.getFist());
    _equiped.push_back(_store.getFist());
}
void Warrior::calcAttack(){
    _attack=(_power*_level)+_strength+(*_equiped[0])->getWeaponpower()+(*_equiped[1])->getWeaponpower();
    _defence=(_protection*_level)+_shield;
}
Warrior::Warrior(const Warrior &W):Character(W){
    _shield=W._shield;
    _strength=W._strength;

}
void Warrior::equipWeapon(int pos, int hand){
    if(pos==-1){
        _equiped[hand]=_store.getFist();
    }
    else{
        for (int i=0;i<2;i++){
            if(i==0){
                cout<<"left hand:"<<endl;
            }
            else{
                cout<<"right hand:"<<endl;
            }
            (*_equiped[i])->display();
        }
        if(hand==0){
            cout<<"changing left hand"<<endl;
        }
        else{
            cout<<"changing right hand"<<endl;
        }
        _equiped[hand]=&(*_inventory.getWeDirect())[pos];
    }
}
void Warrior::display(){
    cout<<endl<<"shield: "<<_shield<<endl;
    cout<<endl<<"strength: "<<_strength<<endl;
    cout<<endl<<"Weapons equiped:"<<endl;
    for(int i=0;i<2;i++){
        cout<<"   "<<i+1<<"."<<endl;
        (*_equiped[i])->display();
    }
    cout<<endl<<"Combat: "<<endl;
    this->calcAttack();
    cout<<endl<<"   Attack: "<<_attack<<endl<<"   Defence: "<<_defence<<endl;
}
void Warrior::statsXp(){
    int power=2+2*(_level-1);
    int protection=15+_level;
    if (_level==1){
        --protection;
    }
    if(_power>=power&&_protection>=protection&&_strength>=_level){
        _inventory.addMoney(2);
    }
    else{
        if(_power<power){
            _power=power;
        }
        if(_protection<protection){
            _protection=protection;
        }
        if(_strength<_level){
            _strength=_level;
        }
    }



}
