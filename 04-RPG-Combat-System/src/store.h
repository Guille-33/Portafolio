#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include "weapon.h"
#include <vector>
#include "inventory.h"

using namespace std;

class Store
{
    public:
        Store();
        ~Store();
        void display();
        void setStore(int id);
        int buy_Item(string type,Inventory& invent);
        void sell_Item(int item, int pos, Inventory &invent);
        vector<vector<Weapon>> getWeaponssale(){return Weapons_for_sale;}
        Weapon** getFist(){return &_fist;}
    private:
        int _id;
        int _i;
        vector<vector<int> > _shoping_costs_w;
        vector<vector<int> > _selling_costs_w;
        vector<vector<Weapon> > Weapons_for_sale;
        int _other_Items[2][5];
        int _price_Spells;
        Weapon*_fist=new Weapon();
};

#endif
