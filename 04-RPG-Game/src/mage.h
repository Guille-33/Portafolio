#ifndef MAGE_H
#define MAGE_H
#include <iostream>
#include <string>
#include "spells.h"
#include "character.h"


using namespace std;

class Mage: public Character
{
private:
    int _mana;
    Spells *_spells=new  Spells [4]; //one for each type
    int _extreme_stats[2][4]={{0,1,50,50},{100,12,60,70}};
    int _attack;
    int _defence;
    Weapon** _equiped;
public:
    Mage();
    Mage(string name);
    Mage(string name, int health, int accuary, int protection, int power, int level,int xp,int money,int mana);
    Mage(const Mage &M);
    ~Mage(){delete _equiped;delete _spells;}
    void setMana(int mana);
    void setSpells(string type,int power,int mana_cost);//NOT NECESSARY
    void display();
    int getMana();
    int getSpells(string type,string what); //Type and what you want,either mana or power(aflicction to the enemy)
    void subsMana(int mana);
    void equipWeapon(int pos);
    void statsXp();
    int getAttack(){this->calcAttack();return _attack;}
    int getDefence(){this->calcAttack();return _defence;}
    void calcAttack();

    void setWaterm(){_spells[0].setWater();}
    void setEarthm(){_spells[1].setEarth();}
    void setFirem(){_spells[2].setFire();}
    void setAirm(){_spells[3].setAir();}
    void eraseSm(int i){_spells[i].erase();}

    string getspells_Type(int i){return _spells[i].getType();}
    string getW_type(){return (*_equiped)->getWeaponType();}
    int getW_lvl(){return (*_equiped)->getWeaponNivel();}
    Weapon** getEquiped(){return _equiped;}
};

#endif // MAGE_H
