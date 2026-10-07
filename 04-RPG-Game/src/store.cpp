#include "store.h"
#include "string"

Store::Store()
{
    _id=0;
    _other_Items[0][0]=20;
    _other_Items[0][1]=30;
    _other_Items[0][2]=50;
    _other_Items[0][3]=25;
    _other_Items[0][4]=10;
    _other_Items[1][0]=10;
    _other_Items[1][1]=30;
    _other_Items[1][2]=35;
    _other_Items[1][3]=10;
    _other_Items[1][4]=5;
    _price_Spells=45;
}

void Store::setStore(int id)
{
        _id=id;
        switch(_id)
        {
            case 1:_i=2;
                break;
            case 2:
            case 3:_i=1;
                break;
        }
        Weapon weapon1;
        Weapons_for_sale.resize(_i, vector<Weapon>(5));
        _shoping_costs_w.resize(_i, vector<int>(5));
        _selling_costs_w.resize(_i, vector<int>(5));
        if(_id==1)
        {
            for (int I=0; I<_i; I++)
            {
                for (int J=0; J<5; J++)
                {
                    Weapons_for_sale[I][J]=weapon1;
                    if (I==0)
                    {
                        Weapons_for_sale[I][J].setsword(J+1);
                    }
                    if (I==1)
                    {
                        Weapons_for_sale[I][J].setsmaze(J+1);
                    }
                }
            }
            for(int i=0; i<2; i++)
            {
                for(int j=0; j<5; j++)
                {

                        if (j==0)
                        {
                            _selling_costs_w[i][j]=5;
                            _shoping_costs_w[i][j]=7;
                        }

                        if (j==1)
                        {
                            _selling_costs_w[i][j]=7;
                            _shoping_costs_w[i][j]=10;
                        }

                        if (j==2)
                        {
                            _selling_costs_w[i][j]=15;
                            _shoping_costs_w[i][j]=25;
                        }

                        if (j==3)
                        {
                            _selling_costs_w[i][j]=25;
                            _shoping_costs_w[i][j]=40;
                        }

                        if (j==4)
                        {
                            _selling_costs_w[i][j]=50;
                            _shoping_costs_w[i][j]=50;
                        }
                }
            }
      }
    if (_id==2)
        {
            for (int I=0; I<_i; I++)
            {
                for (int J=0; J<5; J++)
                {
                    Weapons_for_sale[I][J]=weapon1;
                    Weapons_for_sale[I][J].setsbow(J+1);
                }
            }
            for(int j=0; j<5; j++)
            {
                if (j==0)
                {
                    _selling_costs_w[0][j]=7;
                    _shoping_costs_w[0][j]=10;
                }
                else{
                    _shoping_costs_w[0][j]=_shoping_costs_w[0][j-1]+10;
                }
                if (j==1)
                {
                    _selling_costs_w[0][j]=10;
                }

                if (j==2)
                {
                    _selling_costs_w[0][j]=15;
                }

                if (j==3)
                {
                    _selling_costs_w[0][j]=20;
                }

                if (j==4)
                {
                    _selling_costs_w[0][j]=70;
                    _shoping_costs_w[0][j]=70;
                }
            }
      }
    if (_id==3)
    {
        for (int I=0; I<_i; I++)
        {
            for (int J=0; J<5; J++)
            {
                Weapons_for_sale[I][J]=weapon1;
                switch (J)
                {
                    case 0:Weapons_for_sale[I][J].setstaff("Basic");
                        break;
                    case 1:Weapons_for_sale[I][J].setstaff("Water");
                        break;
                    case 2:Weapons_for_sale[I][J].setstaff("Earth");
                        break;
                    case 3:Weapons_for_sale[I][J].setstaff("Fire");
                        break;
                    case 4:Weapons_for_sale[I][J].setstaff("Air");
                        break;
                }
            }
        }
        for(int j=0; j<5; j++)
        {
            if (j==0)
            {
                _selling_costs_w[0][j]=20;
                _shoping_costs_w[0][j]=20;
            }
            else
            {
                _selling_costs_w[0][j]=30;
                _shoping_costs_w[0][j]=60;
            }
        }
    }
}


void Store::display()
{
    switch(_id)
    {
        case 1:_i=2;
            break;
        case 2:
        case 3:_i=1;
            break;
    }
    for (int I=0; I<_i; I++)
    {
                for (int J=0; J<5; J++)
                {
                    Weapons_for_sale[I][J].display();
                    cout<<"Price:"<<_shoping_costs_w[I][J]<<endl;
                    cout<<"Selling price:"<<_selling_costs_w[I][J]<<endl<<endl;
                }
    }
    for (int J=0; J<5; J++)
    {
     switch (J)
     {
        case 0: cout<<endl<<"Health Potion:"<<endl<<endl<<"Price:"<<_other_Items[0][J]<<endl<<"Selling price:"<<_other_Items[1][J]<<endl;
            break;
        case 1: if (_id==3)
        {
            cout<<endl<<endl<<"Mana Potion:"<<endl<<endl<<"Price:"<<_other_Items[0][J]<<endl<<"Selling price:"<<_other_Items[1][J]<<endl;
        }
            break;
        case 2: cout<<endl<<endl<<"Xp Potion:"<<endl<<endl<<"Price:"<<_other_Items[0][J]<<endl<<"Selling price:"<<_other_Items[1][J]<<endl;
            break;
        case 3:  if (_id==1)
        {
            cout<<endl<<endl<<"Warrior Armour:"<<endl<<endl<<"Price:"<<_other_Items[0][J]<<endl<<"Selling price:"<<_other_Items[1][J]<<endl;
        }
            break;
        case 4:if (_id==2)
        {
            cout<<endl<<endl<<"Archer Arrows:"<<endl<<endl<<"Price:"<<_other_Items[0][J]<<endl<<"Selling price:"<<_other_Items[1][J]<<endl;
        }
            break;
     }
    }
    if (_id==3)
    {
        cout<<endl<<endl<<"Price Spells:"<<_price_Spells<<endl<<endl<<"Disclaimer:By buiying an spell,you lose your turn"<<endl;
    }
}

Store::~Store()
{
    delete _fist;
    _shoping_costs_w.clear();
    _selling_costs_w.clear();
    Weapons_for_sale.clear();
}

int Store::buy_Item(string type, Inventory& invent)
{
    Potions pots=invent.getPotions();
    int p;
    int m=invent.getMoney();
    int arma;
    int tipo;
    long unsigned int i;
    for (i=0;i<type.size();i++){
        if(type[i]==95){
            break;
        }
    }
    string palabra=type.substr(i+1,type.size()-i+1);
    if (palabra =="Maze"){
        arma=1;
    }
    else if(palabra=="Sword"||palabra=="Potion"||palabra=="Armour"||palabra=="Bow"||palabra=="Arrow"||palabra=="Staff"||palabra=="Spells"){
        arma=0;
    }
    palabra = type.substr(0,i);
    if(palabra=="Basic"||palabra=="Health"){
        tipo=0;
    }
    else if(palabra=="Common"||palabra=="Mana"||palabra=="Water"||palabra=="Spells"){
        tipo=1;
    }
    else if(palabra=="Uncommon"||palabra=="Xp"||palabra=="Earth"){
        tipo=2;
    }
    else if(palabra=="Epic"||palabra=="Warrior"||palabra=="Fire"){
        tipo=3;
    }
    else if(palabra=="Legendary"||palabra=="Archer"||palabra=="Air"){
        tipo=4;
    }
    else{
        return -1;
    }
    palabra=type.substr(i+1,type.size()-i+1);
    if(_id==1)
    {
        if (palabra=="Potion"){
            if (m-_other_Items[arma][tipo]<0)
            {
                cout<<"There is not enough money to do this transaction"<<endl;
            }
            if (m-_other_Items[arma][tipo]>=0)
            {
                switch (tipo) {
                case 0:
                    p=pots.getPotion_h();
                    if (p==0)
                    {
                        cout<<"Transaction accepted"<<endl;
                        invent.subsMoney(_other_Items[arma][tipo]);
                        invent.addPot("health",p+1);
                    }
                    else
                    {
                        cout<<"You already carry a potion in your inventory"<<endl;
                    }
                    break;
                case 2:
                    p=pots.getPotion_xp();
                    cout<<"Transaction accepted"<<endl;
                    invent.subsMoney(_other_Items[arma][tipo]);
                    invent.addPot("xp",p+1);
                    break;
                default:
                    break;
                }

            }
        }
        else if(palabra=="Armour"){
            if (m-_other_Items[arma][tipo]<0)
            {
                cout<<"There is not enough money to do this transaction"<<endl;
            }
            else
            {
                return _other_Items[arma][tipo];
            }
        }
        else if(palabra=="Sword"||palabra=="Maze"){
              if (m-_shoping_costs_w[arma][tipo]<0)
              {
                  cout<<"There is not enough money to do this transaction"<<endl;
              }
              if (m-_shoping_costs_w[arma][tipo]>=0)
              {
                  cout<<"Transaction accepted"<<endl;
                  invent.subsMoney(_shoping_costs_w[arma][tipo]);
                  invent.addWeap(&Weapons_for_sale[arma][tipo]);
              }
        }


    }
    if(_id==2)
    {
        if (palabra=="Potion"){
            if (m-_other_Items[arma][tipo]<0)
            {
                cout<<"There is not enough money to do this transaction"<<endl;
            }
            if (m-_other_Items[arma][tipo]>=0)
            {
                switch (tipo) {
                case 0:
                    p=pots.getPotion_h();
                    if (p==0||p==1)
                    {
                        cout<<"Transaction accepted"<<endl;
                        invent.subsMoney(_other_Items[arma][tipo]);
                        invent.addPot("health",p+1);
                    }
                    else
                    {
                        cout<<"You already carry a potion in your inventory"<<endl;
                    }
                    break;
                case 2:
                    p=pots.getPotion_xp();
                    cout<<"Transaction accepted"<<endl;
                    invent.subsMoney(_other_Items[arma][tipo]);
                    invent.addPot("xp",p+1);
                    break;
                default:
                    break;
                }

            }
        }
        else if (palabra=="Arrow") {
            if (m-_other_Items[arma][tipo]<0)
            {
                cout<<"There is not enough money to do this transaction"<<endl;
            }
            else
            {
                return _other_Items[arma][tipo];
            }
        }
        else if(palabra=="Bow"){
              if (m-_shoping_costs_w[arma][tipo]<0)
              {
                  cout<<"There is not enough money to do this transaction"<<endl;
              }
              if (m-_shoping_costs_w[arma][tipo]>=0)
              {
                  cout<<"Transaction accepted"<<endl;
                  invent.subsMoney(_shoping_costs_w[arma][tipo]);
                  invent.addWeap(&Weapons_for_sale[arma][tipo]);
              }
        }
    }
    if(_id==3)
    {
        if (palabra=="Potion"){
            if (m-_other_Items[arma][tipo]<0)
            {
                cout<<"There is not enough money to do this transaction"<<endl;
            }
            if (m-_other_Items[arma][tipo]>=0)
            {
                switch (tipo) {
                case 0:
                    p=pots.getPotion_h();
                    if (p==0||p==1)
                    {
                        cout<<"Transaction accepted"<<endl;
                        invent.subsMoney(_other_Items[arma][tipo]);
                        invent.addPot("health",p+1);
                    }
                    else
                    {
                        cout<<"You already carry a potion in your inventory"<<endl;
                    }
                    break;
                case 1:
                    p=pots.getPotion_m();
                    if (p==0)
                    {
                        cout<<"Transaction accepted"<<endl;
                        invent.subsMoney(_other_Items[arma][tipo]);
                        invent.addPot("mana",1);
                    }
                    else
                    {
                        cout<<"You already carry a mana potion in your inventory"<<endl;
                    }
                    break;
                case 2:
                    p=pots.getPotion_xp();
                    cout<<"Transaction accepted"<<endl;
                    invent.subsMoney(_other_Items[arma][tipo]);
                    invent.addPot("xp",p+1);
                    break;
                default:
                    break;
                }

            }
        }
        else if (palabra=="Spells"){
            if (m-_price_Spells<0){
                cout<<"There is not enough money to do this transaction"<<endl;
            }
            if (m-_price_Spells>=0){
                return _price_Spells;
            }
        }
        else if(palabra=="Staff"){
              if (m-_shoping_costs_w[arma][tipo]<0)
              {
                  cout<<"There is not enough money to do this transaction"<<endl;
              }
              if (m-_shoping_costs_w[arma][tipo]>=0)
              {
                  cout<<"Transaction accepted"<<endl;
                  invent.subsMoney(_shoping_costs_w[arma][tipo]);
                  invent.addWeap(&Weapons_for_sale[arma][tipo]);
              }
        }
    }
    return 0;
}
void Store::sell_Item(int item,int pos, Inventory& invent){
    if(item==1){
        for (int I=0; I<_i; I++){
            for (int J=0; J<5; J++){
                if((*invent.getWeDirect())[pos]->getWeaponType()==Weapons_for_sale[I][J].getWeaponType()){
                    (*invent.getWeDirect()).erase((*invent.getWeDirect()).begin()+pos);
                    invent.addMoney(_selling_costs_w[I][J]);
                }
            }
        }
    }
    if (item==0){
        switch (pos) {
        case 0:
            if(invent.getPotionh()>0){
                invent.addMoney(_other_Items[item][pos]);
                invent.addPot("health",-1);
            }
            break;
        case 1:
            if(invent.getPotionm()>0){
                invent.addMoney(_other_Items[item][pos]);
                invent.addPot("mana",-1);
            }
            break;
        case 2:
            if(invent.getpotionxp()>0){
                invent.addMoney(_other_Items[item][pos]);
                invent.addPot("xp",-1);
            }
            break;
        default:
            break;
        }
    }

}
