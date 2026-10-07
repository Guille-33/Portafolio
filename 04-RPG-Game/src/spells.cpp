#include "spells.h"

Spells::Spells()
{
    _type="non";
    _power=0;
    _mana_cost=9999;
}

Spells::Spells(string type,int power,int cost)
{
    _type=type;
    _power=power;
    _mana_cost=cost;
}

Spells::Spells(const Spells &S)
{
    _type=S._type;
    _power=S._power;
    _mana_cost=S._mana_cost;
}

Spells::~Spells()
{
}

void Spells::setType(string type)
{
    _type=type;
}

string Spells::getType()
{
    return _type;
}

void Spells::setPower(int power)
{
    _power=power;
}

int Spells::getPower()
{
    return _power;
}

void Spells::setMana_Cost(int cost)
{
    _mana_cost=cost;
}

int Spells::getMana_Cost()
{
    return _mana_cost;
}


void Spells::display()
{
    cout<<endl<<"  Type:"<<_type<<endl<<"  Power:"<<_power<<endl<<"  Mana Cost:"<<_mana_cost<<endl;
}

void Spells::setAir()
{
    _type="Air";
    _power=1;//-level
    _mana_cost=60;
}

void Spells::setFire()
{
    _type="Fire";
    _power=40;//-ps
    _mana_cost=70;
}

void Spells::setEarth()
{
    _type="Earth";
    _power=0.5;//protection by half
    _mana_cost=50;
}

void Spells::setWater()
{
    _type="Water";
    _power=50;//+ps
    _mana_cost=40;
}
void Spells::erase()
{
    _type="non";
    _power=0;
    _mana_cost=9999;
}
