#ifndef ARCHER_H
#define ARCHER_H
#include "character.h"

using namespace std;

class Archer: public Character
{
    int _arrows;
    int _agility;
    int _attack;
    int _defence;
    int _extreme_stats[2][6]={{0,1,20,0,1,1},{100,12,40,30,15,10}};
    Weapon** _equiped;
public:
    Archer(){}
    Archer(string name);
    Archer(string name, int health, int accuracy, int protection, int power, int level, int arrows, int agility,int xp,int money);
    Archer(const Archer &A);
    ~Archer(){delete _equiped;}
    void setArrows(int arrows){_arrows=arrows;}
    void setAgility(int agility){_agility=agility;}
    void display();
    int getArrows(){return _arrows;}
    int getAgility(){return _agility;}
    int getAttack(){this->calcAttack();return _attack;}
    int getDefence(){this->calcAttack();return _defence;}
    void equipWeapon(int pos);
    void statsXp();
    void calcAttack();
    string getW_type(){return (*_equiped)->getWeaponType();}
    Weapon** getEquiped(){return _equiped;}
    int getW_lvl(){return (*_equiped)->getWeaponNivel();}
};

#endif // ARCHER_H
