#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <vector>
#include <deque>
#include "potions.h"
#include "weapon.h"
using namespace std;


class Inventory
{
    deque <Weapon*>_weaps;
    Potions _pots;
    int _money;
public:
    Inventory(){}
    Inventory(deque <Weapon*> weaps,Potions pots, int money){_weaps=weaps;_pots=pots;_money=money;}
    Inventory(const Inventory &I){_weaps=I._weaps;_pots=I._pots;_money=I._money;}
    ~Inventory(){}
    void addWeap(Weapon *W){_weaps.push_back(W);}
    void addPot(string what, int quant);
    void display();
    Potions getPotions(){return _pots;}
    void setMoney(int money){_money=money;}
    int getMoney(){return _money;}
    void addMoney(int money){_money=_money+money;}
    void subsMoney(int money){_money=_money-money;}
    void setweaps(deque<Weapon*> weaps){_weaps=weaps;}
    int getPotionh(){return _pots.getPotion_h();}
    int getPotionm(){return _pots.getPotion_m();}
    int getpotionxp(){return _pots.getPotion_xp();}
    string getWinv_type(int i){return _weaps[i]->getWeaponType();}
    int getWinv_lvl(int i){return _weaps[i]->getWeaponNivel();}
    int getWinv_size(){return _weaps.size();}
    deque <Weapon*> getWeaps(){return _weaps;}
    deque<Weapon*>* getWeDirect(){return &_weaps;}


    Inventory& operator =(const Inventory& I){
        if(this==&I){
        }
        else{
            _weaps=I._weaps;_pots=I._pots;_money=I._money;
        }
        return *this;
    }
};

#endif // INVENTORY_H
