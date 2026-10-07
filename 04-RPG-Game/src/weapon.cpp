#include "weapon.h"
#include <iostream>
#include <string>

using namespace std;

void Weapon::setfist()
{
 _type="Fists";
 _power=0;
 _extra="No extra hability";
 _lvl=0;
}

void Weapon::setsword(int lvl)
{
    _type="Sword";
    _lvl=lvl;
    switch (lvl)
    {
        case 0: _type="Fists";
                _power=0;
                _extra="No extra hability";
            break;
        case 1: _type="Basic_"+_type;
                _power=6;
                _extra="No extra hability";
            break;
        case 2: _type="Common_"+_type;
                _power=12;
                _extra="No extra hability";
            break;
        case 3: _type="Uncommon_"+_type;
                _power=18;
                _extra="No extra hability";
            break;
        case 4: _type="Epic_"+_type;
                _power=24;
                _extra="For each attack you get plus half of the xp obtained";
            break;
        case 5: _type="Legendary_"+_type;
                _power=30;
                _extra="Each time you find money,you get plus half more";
            break;
    }
}

void Weapon::setsmaze(int lvl)
{
    _type="Maze";
    _lvl=lvl;
    switch (lvl)
    {
        case 0: _type="Fists";
                _power=0;
                _extra="No extra hability";
            break;
        case 1: _type="Basic_"+_type;
                _power=10;
                _extra="No extra hability";
            break;
        case 2: _type="Common_"+_type;
                _power=20;
                _extra="No extra hability";
            break;
        case 3: _type="Uncommon_"+_type;
                _power=30;
                _extra="No extra hability";
            break;
        case 4: _type="Epic_"+_type;
                _power=40;
                _extra="+ 0.25 of accuracy";//range of accuracy you obtain for the play plus the 25% of the range
            break;
        case 5: _type="Legendary_"+_type;
                _power=50;
                _extra="+ 0.5 of accuracy";
            break;
    }
}

void Weapon::setsbow(int lvl)
{
    _type="Bow";
    _lvl=lvl;
    switch (lvl)
    {
        case 0: _type="Fists";
                _power=0;
                _extra="No extra hability";
            break;
        case 1: _type="Basic_"+_type;
                _power=10;
                _extra="No extra hability";
            break;
        case 2: _type="Common_"+_type;
                _power=25;
                _extra="No extra hability";
            break;
        case 3: _type="Uncommon_"+_type;
                _power=40;
                _extra="No extra hability";
            break;
        case 4: _type="Epic_"+_type;
                _power=55;
                _extra="10% of a second attack at half the damage done in the round";//damage done directy to the health of the other player
            break;
        case 5: _type="Legendary_"+_type;
                _power=70;
                _extra="Unlimited arrows,but a half of the agility";
            break;
    }
}

void Weapon::setstaff(string type)
{
    if (type=="Basic")
    {
        _type=type+"_Staff";
        _lvl=1;
        _power=20;
        _extra="No extra hability";
    }
    if (type=="Water")
    {
        _type=type+"_Staff";
        _lvl=2;
        _power=40;
        _extra="+50 Ps to the one who whields it";//cuidado al equipar
    }
    if (type=="Earth")
    {
        _type=type+"_Staff";
        _lvl=2;
        _power=35;
        _extra="-0.5 of accuracy to the ones affected by this spell(has a duration of one round)";
    }
    if (type=="Fire")
    {
        _type=type+"_Staff";
        _lvl=2;
        _power=30;
        _extra="+25% more damage to the fire spell";
    }
    if (type=="Air")
    {
        _type=type+"_Staff";
        _lvl=2;
        _power=25;
        _extra="If a warrior is affected it also will lose it shield,if a mage is affected it will also lose half it's mana";
    }

}

void Weapon::displaytype()
{
    switch(_lvl)
    {
        case 1:cout<<GREY;
            break;
        case 2:cout<<GREEN;
            break;
        case 3:cout<<BLUE;
            break;
        case 4:cout<<PURPLE;
            break;
        case 5:cout<<GOLDEN;
            break;
    }
    cout<<_type;
}

void Weapon::displaylvl()
{
    switch(_lvl)
    {
        case 1:cout<<GREY<<"Level:"<<_lvl;
            break;
        case 2:cout<<GREEN<<"Level:"<<_lvl;
            break;
        case 3:cout<<BLUE<<"Level:"<<_lvl;
            break;
        case 4:cout<<PURPLE<<"Level:"<<_lvl;
            break;
        case 5:cout<<GOLDEN<<"Level:"<<_lvl;
            break;
    }

}

void Weapon::displaypower()
{
    switch(_lvl)
    {
        case 1:cout<<GREY;
            break;
        case 2:cout<<GREEN;
            break;
        case 3:cout<<BLUE;
            break;
        case 4:cout<<PURPLE;
            break;
        case 5:cout<<GOLDEN;
            break;
    }
    cout<<"Power:"<<_power;
}

void Weapon::displayextra()
{
    switch(_lvl)
    {
        case 1:cout<<GREY;
            break;
        case 2:cout<<GREEN;
            break;
        case 3:cout<<BLUE;
            break;
        case 4:cout<<PURPLE;
            break;
        case 5:cout<<GOLDEN;
            break;
    }
    cout<<"Extra Habilities:"<<_extra<<RESET;
}

void Weapon::display()
{
    switch(_lvl)
    {
        case 0:cout<<GREY<<"Level:"<<_lvl<<endl;
            break;
        case 1:cout<<GREY<<"Level:"<<_lvl<<endl;
            break;
        case 2:cout<<GREEN<<"Level:"<<_lvl<<endl;
            break;
        case 3:cout<<BLUE<<"Level:"<<_lvl<<endl;
            break;
        case 4:cout<<PURPLE<<"Level:"<<_lvl<<endl;
            break;
        case 5:cout<<GOLDEN<<"Level:"<<_lvl<<endl;
            break;
    }
    cout<<_type<<endl;
    cout<<"Power:"<<_power<<endl;
    cout<<"Extra Habilities:"<<_extra<<RESET<<endl;;
}

Weapon::Weapon(string type,int lvl){
    if (type=="Sword"){
        this->setsword(lvl);
    }
    else if(type=="Bow"){
        this->setsbow(lvl);
    }
    else if(type=="Maze"){
        this->setsmaze(lvl);
    }
    else if(type=="Fist"){
        this->setfist();
    }
    else {
        this->setstaff(type);
    }
}
