#ifndef SPELLS_H
#define SPELLS_H
#include <iostream>
#include <string>

using namespace std;

class Spells
{
    public:
        Spells();
        Spells(string type,int power,int mana_cost);
        Spells(const Spells &S);
        ~Spells();

        void setType(string type);
        string getType();
        void setPower(int power);
        int getPower();
        void setMana_Cost(int cost);
        int getMana_Cost();
        void display();
        void setFire();
        void setWater();
        void setEarth();
        void setAir();
        void erase();

        Spells& operator =(const Spells& S){
            if(this==&S){}
            else{
                _type=S._type;
                _power=S._power;
                _mana_cost=S._mana_cost;
            }
            return *this;
        }

    protected:
        string _type;
        int _power;
        int _mana_cost;
};

#endif
