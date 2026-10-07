#ifndef POTIONS_H
#define POTIONS_H

class Potions
{
    public:
        Potions();
        Potions(int h,int m,int xp);
        Potions(const Potions &P);
        ~Potions();
        void setPotion_h(int h);
        int getPotion_h();
        void setPotion_m(int m);
        int getPotion_m();
        void setPotion_xp(int xp);
        int getPotion_xp();
        void display();
        void usepotion_h();
        void usepotion_m();
        void usepotion_xp();

        Potions& operator=(const Potions& P){
            if(this==&P){
            }
            else{
                _potion_h=P._potion_h;
                _potion_m=P._potion_m;
                _potion_xp=P._potion_xp;
            }
            return *this;
        }

    private:
        int _potion_h;
        int _potion_m;
        int _potion_xp;
};

#endif
