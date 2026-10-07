#ifndef WARRIOR_H
#define WARRIOR_H
#include "character.h"
#include "weapon.h"
using namespace std;


    class Warrior: public Character
    {
        int _shield;
        int _strength;
        int _attack;
        int _defence;
        int _extreme_stats[2][6]={{0,1,15,0,0,1},{100,12,30,30,30,15}};
        deque <Weapon**> _equiped;
    public:
        Warrior(){}
        Warrior(string name);
        Warrior(string name, int health, int accuracy, int protection, int power, int level, int shield, int strength,int xp,int money);
        Warrior(const Warrior &W);
        ~Warrior(){_equiped.clear();}
        void setShield(int shield){_shield=shield;}
        void setStrength(int strength){_strength=strength;}
        void display();
        int getShield(){return _shield;}
        int getStrength(){return _strength;}
        int getAttack(){this->calcAttack();return _attack;}
        int getDefence(){this->calcAttack();return _defence;}
        void equipWeapon(int pos, int hand);
        void statsXp()override;
        void calcAttack();
        deque <Weapon**> getEquiped(){return _equiped;}

        string getW_type(int i){return (*_equiped[i])->getWeaponType();}
        int getW_lvl(int i){return (*_equiped[i])->getWeaponNivel();}
    };



#endif // WARRIOR_H
