#include <iostream>
#include "mage.h"
#include "character.h"
#include "spells.h"
#include <cstdlib>
#include <ctime>

using namespace std;



Mage::Mage(string name):Character(name,"mg")
{
    _store.setStore(3);
    _equiped=_store.getFist();
    _mana=100;
    int lB = 0;
        int uB = 3;
        srand(time(NULL));
        int spell1=lB+rand()%(uB-lB+1);
        switch(spell1)
        {
        case 0:_spells[0].setAir();
              break;
            case 1:_spells[1].setFire();
              break;
        case 2:_spells[2].setEarth();
              break;
        case 3:_spells[3].setWater();
              break;
    }
    int spell2=lB+rand()%(uB-lB+1);
    while(spell2==spell1)
    {
    spell2=lB+rand()%(uB-lB+1);
    }
    switch(spell2)
        {
        case 0:_spells[0].setAir();
              break;
            case 1:_spells[1].setFire();
              break;
        case 2:_spells[2].setEarth();
              break;
        case 3:_spells[3].setWater();
              break;
    }
}

void Mage::setMana(int mana){
    _mana=mana;
}
void Mage::subsMana(int mana){
    _mana=_mana-mana;
}
int Mage::getMana(){
    return _mana;
}
Mage::Mage(string name, int health, int accuary, int protection, int power, int level, int xp, int money,int mana):Character(name,health,accuary,protection,power,level,xp,money){
    _store.setStore(3);
    _equiped=_store.getFist();
    _mana=mana;
    int lB = 0;
    int uB = 3;
    srand(time(NULL));
    int spell1=lB+rand()%(uB-lB+1);
    switch(spell1)
    {
        case 0:_spells[0].setWater();
               break;
        case 1:_spells[1].setEarth();
               break;
        case 2:_spells[2].setFire();
               break;
        case 3:_spells[3].setAir();
               break;
    }
    int spell2;
    do{
        spell2=lB+rand()%(uB-lB+1);
    }while (spell2==spell1);

    switch(spell2)
    {
    case 0:_spells[0].setWater();
           break;
    case 1:_spells[1].setEarth();
           break;
    case 2:_spells[2].setFire();
           break;
    case 3:_spells[3].setAir();
           break;
    }
}
Mage::Mage()
{
 _mana=0;
}

void Mage::calcAttack(){
    _attack=(_power*_level)+(*_equiped)->getWeaponpower();
    _defence=_protection*_level;
}

int Mage::getSpells(string type, string what){
    for (int i=0;i<4;i++){
        if (type==_spells[i].getType()){
            if (what=="mana"){
                return _spells[i].getMana_Cost();
            }
            if (what=="power"){
                return _spells[i].getPower();
            }
            break;
        }
    }
    return 0;
}
void Mage::setSpells(string type, int power, int mana_cost){
    for (int i=0;i<4;i++){
        if (_spells[i].getType()=="non"){
            _spells[i].setType(type);
            _spells[i].setPower(power);
            _spells[i].setMana_Cost(mana_cost);
        }
        break;
    }
}
Mage::Mage(const Mage &M):Character(M){
    _mana=M._mana;
    for (int i=0;i<4;i++){
        _spells[i]=M._spells[i];
    }
}
void Mage::display(){

    cout<<endl<<"Mana: "<<_mana<<endl;
    cout<<endl<<"Spells:";
    for(int i=0;i<4;i++)
    {
        string Type=_spells[i].getType();
        if (Type!="non")
        {
            _spells[i].display();
        }
     }
    this->calcAttack();
    cout<<endl<<"Combat:"<<endl<<"   Attack: "<<_attack<<endl<<"   Defence: "<<_defence<<endl;
}
void Mage::equipWeapon(int pos){
    (*_equiped)->display();
    cout<<"changing weapon"<<endl;
    if((*_inventory.getWeDirect()).size()>=pos){
        _equiped=&(*_inventory.getWeDirect())[pos];
    }
}
void Mage::statsXp(){
    int power=50+(_level-1)+3*((_level-1)/7);
    int protection=50+(_level/2);
    if(_level>10){
        protection=protection+((_level-9)/2);
    }
    if(_power>=power&&_protection>=protection){
        _inventory.addMoney(2);
    }
    else{
        if(_power<power){
            _power=power;
        }
        if(_protection<protection){
            _protection=protection;
        }
    }
}
