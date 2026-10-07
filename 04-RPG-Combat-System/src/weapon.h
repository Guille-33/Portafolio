#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
//#include "inventory.h"

using namespace std;

const string RESET   = "\033[0m";
const string BLACK   = "\033[30m";
const string RED     = "\033[31m";
const string GREEN   = "\033[32m";
const string YELLOW  = "\033[33m";
const string BLUE    = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN    = "\033[36m";
const string WHITE   = "\033[37m;1m";
const string GREY    = "\033[37m";
const string PURPLE = "\033[35m";
const string GOLDEN = "\033[33;1m";




class Weapon
{
    string _type;
    int _power;
    string _extra;
    int _lvl;
public:
    Weapon(){setfist();}
    ~Weapon(){}
    Weapon(string type, int lvl);
    Weapon(const Weapon &W){_type=W._type;_power=W._power;_extra=W._extra;_lvl=W._lvl;}
    string getWeaponType (){return _type;}
    int getWeaponpower (){return _power;}
    string getWeaponExtra(){return _extra;}
    int getWeaponNivel(){return _lvl;}
    void setsword(int lvl);
    void setsmaze(int lvl);
    void setsbow(int lvl);
    void setstaff(string type);
    void displaytype();
    void displaypower();
    void displayextra();
    void setfist();
    void displaylvl();
    void display();

    Weapon& operator =(const Weapon& W){
        if(this==&W){
        }
        else{
            _type=W._type;_power=W._power;_extra=W._extra;_lvl=W._lvl;
        }
        return *this;
    }
};

#endif // WEAPON_H
