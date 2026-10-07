#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "inventory.h"
#include "store.h"


using namespace std;

    class Character
    {
    protected:
        int _health;
        int _accuracy;
        int _protection;
        int _power;
        string _name;
        int _level;
        int _xp;
        Inventory _inventory;
    public:
        Store _store;
        Character(){}
        Character(string name,int w);//lv1 constructor warrior
        Character(string name,char a);//lv1 constructor archer
        Character(string name,string mg);//lv1 constructor mage
        Character(string name, int health, int accuary, int protection, int power,int level,int xp,int money);
        Character(const Character&C);
        ~Character(){}
        void setHealth(int health);
        void setAccuary(int accuracy);
        void setProtection(int protection);
        void setPower(int power);
        void setLevel(int level);
        void addPotinv(string what, int quant){_inventory.addPot(what,quant);}
        void setweapsinv(deque<Weapon*> weaps){_inventory.setweaps(weaps);}
        virtual void display();
        void essentialDisplay(int team);
        int getHealth();
        int getAccuracy();
        int getProtection();
        int getPower();
        int getLevel();
        int getXp(){return _xp;}
        string getName(){return _name;}
        void addXp(int xp);
        virtual void statsXp()=0;
        int getinventory_m(){return _inventory.getMoney();}
        int getinventory_ph(){return _inventory.getPotionh();}
        int getinventory_pm(){return _inventory.getPotionm();}
        int getinventory_pxp(){return _inventory.getpotionxp();}
        string getinventory_W_type(int i){return _inventory.getWinv_type(i);}
        int getinventory_W_lvl(int i){return _inventory.getWinv_lvl(i);}
        int getinventory_W_size(){return _inventory.getWinv_size();}
        void displayinv(){_inventory.display();}
        Inventory getInventory(){return _inventory;}
        Inventory* getInventoryDirect(){return &_inventory;}
    };


#endif // CHARACTER_H
