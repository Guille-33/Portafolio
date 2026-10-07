#include <iostream>
#include <string>
#include "potions.h"

using namespace std;

Potions::Potions()
{
    _potion_h=0;
    _potion_m=0;
    _potion_xp=0;
}

Potions::Potions(int h,int m,int xp)
{
    _potion_h=h;
    _potion_m=m;
    _potion_xp=xp;
}

Potions::Potions(const Potions &P)
{
    _potion_h=P._potion_h;
    _potion_m=P._potion_m;
    _potion_xp=P._potion_xp;
}

Potions::~Potions()
{

}

void Potions::setPotion_h(int h)
{
    _potion_h=h;
}

int Potions::getPotion_h()
{
    return _potion_h;
}

void Potions::setPotion_m(int m)
{
    _potion_m=m;
}

int Potions::getPotion_m()
{
    return _potion_m;
}

void Potions::setPotion_xp(int xp)
{
    _potion_xp=xp;
}

int Potions::getPotion_xp()
{
    return _potion_xp;
}

void Potions::display()
{
    cout<<"Health potions:"<<_potion_h<<endl<<"Mana potions:"<<_potion_m<<endl<<"Xp potions:"<<_potion_xp<<endl;
}

void Potions::usepotion_h()
{
    _potion_h=_potion_h-1;
}

void Potions::usepotion_m()
{
    _potion_m=_potion_m-1;
}

void Potions::usepotion_xp()
{
    _potion_xp=_potion_xp-1;
}
