#include "inventory.h"
#include <iostream>
#include <vector>
#include "weapon.h"

using namespace std;

void Inventory::display(){
    cout<<endl<<endl<<"Weapons"<<endl;
    for (long unsigned int i=0;i<_weaps.size();i++){
        _weaps[i]->display();
    }
    cout<<endl<<endl<<"Potions"<<endl;
    _pots.display();
}
void Inventory::addPot(string what,int quant){
    if(what== "mana"){
        _pots.setPotion_m(_pots.getPotion_m()+quant);
    }
    if(what== "health"){
        _pots.setPotion_h(_pots.getPotion_h()+quant);
    }
    if(what== "xp"){
        _pots.setPotion_xp(_pots.getPotion_xp()+quant);
    }
}
