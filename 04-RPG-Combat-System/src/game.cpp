#include "game.h"
#include "mage.h"
#include "character.h"
#include "warrior.h"
#include "archer.h"

using namespace std;

Game::Game()
{
    _i=0;
    _Teams.resize(2);
    _Graveyard.resize(2);
    time_t Actual=time(nullptr);
    char Actual_converted[50];
    strftime(Actual_converted, sizeof(Actual_converted), "(%Y-%m-%d__%H:%M)", localtime(&Actual));
    string Actual_converted_str=Actual_converted;
    action_log_f=n_a_log+Actual_converted_str+extension;
    action_log.push_back("");
}

void Game::act_action_log(int op, int deff_c, int deff_i)
{
    ofstream output(action_log_f,ios::app);
    switch (op)
    {
        case 1:
            output<<_Teams[_team][_player]->getName()<<" Attacked "<<_Teams[deff_i][deff_c]->getName()<<endl;
            action_log.back()=_Teams[_team][_player]->getName() + " Attacked " + _Teams[deff_i][deff_c]->getName();
            action_log.push_back("");
            break;
        case 2:output<<_Teams[_team][_player]->getName()<<" Killed "<<_Teams[deff_i][deff_c]->getName()<<endl;
            action_log.back()=_Teams[_team][_player]->getName()+" Killed "+_Teams[deff_i][deff_c]->getName();
            action_log.push_back("");
            break;
        case 3:output<<_Teams[_team][_player]->getName()<<"'s attack failed"<<endl;
            action_log.back()=_Teams[_team][_player]->getName()+"'s attack failed";
            action_log.push_back("");
            break;
        case 4:output<<_Teams[_team][_player]->getName()<<" Becamed level "<<_Teams[_team][_player]->getLevel()<<endl;
            action_log.back()=_Teams[_team][_player]->getName()+" Becamed level "+to_string(_Teams[_team][_player]->getLevel());
            action_log.push_back("");
            break;
        case 5:output<<"Game started"<<endl;
               action_log.back()="Game started";
               action_log.push_back("");
               break;
        case 6:
                if(_team==0)
                {
                    output<<"Team A WON"<<endl;
                    action_log.back()="Team A WON";
                    action_log.push_back("");
                }
                if(_team==1)
                {
                    output<<"Team B WON"<<endl;
                    action_log.back()="Team B WON";
                    action_log.push_back("");
                }
    }
    output.close();
}



void Game::displayTeam(){
            for (long unsigned int i=0;i<_Teams[_team].size();i++){
                cout<<"display"<<endl;
                _Teams[_team][i]->Character::display();
            }
}

void Game::saveProgress()
{
    time_t Actual=time(nullptr);
    char Actual_converted[50];
    strftime(Actual_converted, sizeof(Actual_converted), "(%Y-%m-%d__%H:%M)", localtime(&Actual));
    string Actual_converted_str=Actual_converted;
    string name_out=n_Out+Actual_converted_str+extension;
    try
    {
        ofstream output(name_out);
        if(!output.is_open())
        {
            throw runtime_error("Error:Failure to create an archive");
        }
        for(int n=0;n<2;n++)
        {
            if(n==0)
            {
                output<<"Team A"<<endl;
            }
            if(n==1)
            {
                output<<"Team B"<<endl;
            }
            for(long unsigned int i=0;i<_Teams[n].size();i++)
            {
                if(dynamic_cast<Warrior*>(_Teams[n][i])!= nullptr)
                {
                   Warrior* w=dynamic_cast<Warrior*>(_Teams[n][i]);
                   output<<"Warrior "<<w->getName()<<endl;
                   output<<w->getHealth()<<endl;
                   output<<w->getLevel()<<endl;
                   output<<w->getXp()<<endl;
                   output<<w->getPower()<<endl;
                   output<<w->getProtection()<<endl;
                   output<<w->getAccuracy()<<endl;
                   output<<w->getinventory_m()<<endl;
                   output<<w->getStrength()<<endl;
                   output<<w->getShield()<<endl;
                   for (int i=0;i<2;i++)
                   {
                       output<<w->getW_type(i)<<":"<<w->getW_lvl(i)<<endl;
                   }
                   output<<w->getinventory_ph()<<"/"<<w->getinventory_pxp()<<endl;
                   for (int i=0;i<w->getinventory_W_size();i++)
                   {
                       output<<w->getinventory_W_type(i)<<":"<<w->getinventory_W_lvl(i)<<endl;
                   }
                   output<<"/n"<<endl;
                   output<<"/n"<<endl;
                }
                else if(dynamic_cast<Archer*>(_Teams[n][i])!= nullptr)
                {
                    Archer* w=dynamic_cast<Archer*>(_Teams[n][i]);
                    output<<"Archer "<<w->getName()<<endl;
                    output<<w->getHealth()<<endl;
                    output<<w->getLevel()<<endl;
                    output<<w->getXp()<<endl;
                    output<<w->getPower()<<endl;
                    output<<w->getProtection()<<endl;
                    output<<w->getAccuracy()<<endl;
                    output<<w->getinventory_m()<<endl;
                    output<<w->getAgility()<<endl;
                    output<<w->getArrows()<<endl;
                    output<<w->getW_type()<<":"<<w->getW_lvl()<<endl;
                    output<<w->getinventory_ph()<<"/"<<w->getinventory_pxp()<<endl;
                    for (int i=0;i<w->getinventory_W_size();i++)
                    {
                        output<<w->getinventory_W_type(i)<<":"<<w->getinventory_W_lvl(i)<<endl;
                    }
                    output<<"/n"<<endl;
                    output<<"/n"<<endl;
                }
                else if(dynamic_cast<Mage*>(_Teams[n][i])!= nullptr)
                {
                    Mage* w=dynamic_cast<Mage*>(_Teams[n][i]);
                    output<<"Mage "<<w->getName()<<endl;
                    output<<w->getHealth()<<endl;
                    output<<w->getLevel()<<endl;
                    output<<w->getXp()<<endl;
                    output<<w->getPower()<<endl;
                    output<<w->getProtection()<<endl;
                    output<<w->getAccuracy()<<endl;
                    output<<w->getinventory_m()<<endl;
                    output<<w->getMana()<<endl;
                    for (int i=0;i<4;++i)
                    {
                       output<<w->getspells_Type(i)<<endl;
                    }
                    output<<w->getW_type()<<":"<<w->getW_lvl()<<endl;
                    output<<w->getinventory_ph()<<"/"<<w->getinventory_pxp()<<"/"<<w->getinventory_pm()<<endl;
                    for (int i=0;i<w->getinventory_W_size();i++)
                    {
                        output<<w->getinventory_W_type(i)<<":"<<w->getinventory_W_lvl(i)<<endl;
                    }
                    output<<"/n"<<endl;
                    output<<"/n"<<endl;
                }
            }
        }
        output<<"/n";
       output.close();
       _i=0;
    } catch (runtime_error &e)
    {
        cout<<e.what()<<endl;
        if (_i<3)
        {
            _i=_i+1;
            this->saveProgress();
        }
    }
}

int Game::findachar(string line, char obj)
{
    for (long unsigned int i=0;i<line.size();i++)
    {
        if (line[i]==obj)
            {
                return i;
            }
    }
        return -1;
}

int Game::loadGame(string input)
{
    try
    {
        string line;
        int I;//0 team a,1 team b
        int i=0;
        int count_ws=0;
        int id=0;
        string name;
        int health;
        int accuracy;
        int protection;
        int power;
        int level;
        int shield;
        int strength;
        int xp;
        int moneh;
        int agility;
        int arrows;
        vector <Weapon> equip;
        ifstream input_f(input);
        if (!input_f.is_open())
        {
            throw runtime_error("Error:Failure to open the archive");
        }
        while (getline(input_f,line))
        {
            if (line=="/n")
            {
                count_ws=count_ws+1;
                if (count_ws==2 or count_ws==3)
                {
                    if (count_ws==2)
                    {
                        i=0;
                        id=0;
                        if(_Teams[I].back()!=nullptr)
                        {
                            for (long unsigned int pos=0;pos<_Teams[I].back()->getInventory().getWeaps().size();pos++){
                                for (long unsigned int we=0;we<equip.size();we++){
                                    if(equip[we].getWeaponType()==_Teams[I].back()->getInventory().getWeaps()[pos]->getWeaponType()){
                                        if (dynamic_cast<Warrior*>(_Teams[I].back())!=nullptr){
                                            dynamic_cast<Warrior*>(_Teams[I].back())->equipWeapon(pos,we);
                                        }
                                        if (dynamic_cast<Archer*>(_Teams[I].back())!=nullptr){
                                            dynamic_cast<Archer*>(_Teams[I].back())->equipWeapon(pos);
                                        }
                                        if(dynamic_cast<Mage*>(_Teams[I].back())!=nullptr){
                                            dynamic_cast<Mage*>(_Teams[I].back())->equipWeapon(pos);
                                        }
                                    }
                                }
                            }
                        }
                        equip.clear();
                      }
                      if(count_ws==3)
                      {
                          input_f.close();
                          return 1;
                      }
                }
                continue;
            }
            if(line!="/n")
            {
                count_ws=0;
            }
            if (i==0)
            {

                if (line=="Team A")
                {
                    I=0;
                    continue;
                }
                else if (line=="Team B")
                {
                    I=1;
                    continue;
                }
                else
                {
                    int r=findachar(line,' ');
                    cout<<endl<<"r:"<<r<<endl;
                    switch (r)
                    {
                        case 7: id=1;
                            break;
                        case 6: id=2;
                            break;
                        case 4: id=3;
                            break;
                        case -1:
                                return 0;
                            break;
                        default: cout<<"smth is wrong"<<endl;
                                return 0;
                   }
                name=line.substr(r+1,line.size()-r+1);
               }
            }
            if (id==1)
            {


                if (0<=i and i<=9)
                {
                    if (i==1)
                    {
                        health=stoi(line);
                    }
                    if (i==2)
                    {
                        level=stoi(line);
                    }
                    if (i==3)
                    {
                        xp=stoi(line);
                    }
                    if (i==4)
                    {
                        power=stoi(line);
                    }
                    if (i==5)
                    {
                        protection=stoi(line);
                    }
                    if (i==6)
                    {
                        accuracy=stoi(line);
                    }
                    if (i==7)
                    {
                        moneh=stoi(line);
                    }
                    if (i==8)
                    {
                        strength=stoi(line);
                    }
                    if (i==9)
                    {
                        shield=stoi(line);
                        Character *load=new Warrior(name,health,accuracy,protection,power,level,shield,strength,xp,moneh);
                        if (I==0)

                        {
                            addChar_A(load);
                        }
                        if (I==1)
                        {
                            addChar_B(load);
                        }

                     }
                  }
                  if (i>9)
                  {
                      if(i==10)
                      {
                          int r=findachar(line,'_');
                          int r2=findachar(line,':');
                          if (r!=-1)
                          {
                            string sub;
                            sub=line.substr(r+1,r2-r-1);
                            string sub2=line.substr(r2+1,line.size()-r2+1);
                            int lvl=stoi(sub2);
                            Weapon jamon(sub,lvl);
                            equip.push_back(jamon);
                          }
                          if (r==-1)
                          {
                              Weapon juaquin;
                              dynamic_cast<Warrior*>(_Teams[I].back())->equipWeapon(-1,0);
                          }
                      }
                      if(i==11)
                      {
                          int r=findachar(line,'_');
                          int r2=findachar(line,':');
                          if (r!=-1)
                          {
                            string sub;
                            sub=line.substr(r+1,r2-r-1);
                            string sub2=line.substr(r2+1,line.size()-r2+1);
                            int lvl=stoi(sub2);
                            Weapon jamon(sub,lvl);
                            equip.push_back(jamon);
                          }
                          if (r==-1)
                          {
                              Weapon Juaquin;
                              dynamic_cast<Warrior*>(_Teams[I].back())->equipWeapon(-1,1);
                          }
                        }
                      if(i==12)
                      {
                          int r=findachar(line,'/');
                          string sub;
                          sub=line.substr(0,r);
                          string sub2=line.substr(r+1,line.size()-r+1);
                          int ph=stoi(sub);
                          int pxp=stoi(sub2);
                          _Teams[I].back()->addPotinv("health",ph);
                          _Teams[I].back()->addPotinv("xp",pxp);

                      }
                      if(i>=13)
                      {
                          int r=findachar(line,'_');
                          int r2=findachar(line,':');
                          if (r!=-1)
                          {
                            string sub;
                            sub=line.substr(r+1,r2-r-1);
                            string sub2=line.substr(r2+1,line.size()-r2+1);
                            int lvl=stoi(sub2);
                            Weapon jamon(sub,lvl);
                            int mon=_Teams[I].back()->getinventory_m();
                            _Teams[I].back()->getInventoryDirect()->setMoney(1000);
                            _Teams[I].back()->_store.buy_Item(jamon.getWeaponType(),*_Teams[I].back()->getInventoryDirect());
                            _Teams[I].back()->getInventoryDirect()->setMoney(mon);
                          }
                      }
                  }
            }
            if (id==2)
            {
                if (0<i and i<=9)
                {
                    if (i==1)
                    {
                        health=stoi(line);
                    }
                    else if (i==2)
                    {
                        level=stoi(line);
                    }
                    else if (i==3)
                    {
                        xp=stoi(line);
                    }
                    else if (i==4)
                    {
                        power=stoi(line);
                    }
                    else if (i==5)
                    {
                        protection=stoi(line);
                    }
                    else if (i==6)
                    {
                        accuracy=stoi(line);
                    }
                    else if (i==7)
                    {
                        moneh=stoi(line);
                    }
                    else if (i==8)
                    {
                        agility=stoi(line);
                    }
                    else if (i==9)
                    {
                        arrows=stoi(line);
                        Character *load=new Archer(name,health,accuracy,protection,power,level,arrows,agility,xp,moneh);
                        if (I==0)

                        {
                            addChar_A(load);
                        }
                        else if (I==1)
                        {
                            addChar_B(load);
                        }

                     }
                  }
                  else if (i>9)
                  {
                    if (i==10)
                    {
                        int r=findachar(line,'_');
                        int r2=findachar(line,':');
                        if (r!=-1)
                        {
                          string sub;
                          sub=line.substr(r+1,r2-r-1);
                          string sub2=line.substr(r2+1,line.size()-r2+1);
                          int lvl=stoi(sub2);
                          Weapon jamon(sub,lvl);
                          equip.push_back(jamon);
                        }
                        if (r==-1)
                        {
                            Weapon Juaquin;
                            dynamic_cast<Archer*>(_Teams[I].back())->equipWeapon(-1);
                        }
                    }
                    if(i==11)
                    {
                        int r=findachar(line,'/');
                        string sub;
                        sub=line.substr(0,r);
                        string sub2=line.substr(r+1,line.size()-r+1);
                        int ph=stoi(sub);
                        int pxp=stoi(sub2);
                        _Teams[I].back()->addPotinv("health",ph);
                        _Teams[I].back()->addPotinv("xp",pxp);

                    }
                }
                    if(i>=12)
                    {
                        int r=findachar(line,'_');
                        int r2=findachar(line,':');
                        if (r!=-1)
                        {
                          string sub;
                          sub=line.substr(r+1,r2-r-1);
                          string sub2=line.substr(r2+1,line.size()-r2+1);
                          int lvl=stoi(sub2);
                          Weapon jamon(sub,lvl);
                          int mon=_Teams[I].back()->getinventory_m();
                          _Teams[I].back()->getInventoryDirect()->setMoney(1000);
                          _Teams[I].back()->_store.buy_Item(jamon.getWeaponType(),*_Teams[I].back()->getInventoryDirect());
                          _Teams[I].back()->getInventoryDirect()->setMoney(mon);
                        }
                    }

                  }
            if (id==3)
            {
                if (0<i and i<=8)
                {
                    if (i==1)
                    {
                        health=stoi(line);
                    }
                    if (i==2)
                    {
                        level=stoi(line);
                    }
                    if (i==3)
                    {
                        xp=stoi(line);
                    }
                    if (i==4)
                    {
                        power=stoi(line);
                    }
                    if (i==5)
                    {
                        protection=stoi(line);
                    }
                    if (i==6)
                    {
                        accuracy=stoi(line);
                    }
                    if (i==7)
                    {
                        moneh=stoi(line);
                    }
                    if (i==8)
                    {
                        int mana=stoi(line);
                        Character *load=new Mage(name,health,accuracy,protection,power,level,xp,moneh,mana);
                        if (I==0)
                        {
                            addChar_A(load);
                        }
                        if (I==1)
                        {
                            addChar_B(load);
                        }

                     }
                  }
                if (i>=9)
                {

                    Mage *m=dynamic_cast<Mage*>(_Teams[I].back());

                    if (i==9)
                  {
                     if(line=="Water")
                     {
                         if(m->getspells_Type(0)!="Water")
                         {
                             m->setWaterm();
                         }

                     }
                     else
                     {
                            m->eraseSm(0);
                     }
                  }
                 else if (i==10)
                  {
                     if(line=="Earth")
                     {
                        if(m->getspells_Type(1)!="Earth")
                        {
                            m->setEarthm();
                        }
                     }
                     else
                     {
                            m->eraseSm(1);
                     }
                  }
                  else if (i==11)
                  {
                     if(line=="Fire")
                     {
                        if(m->getspells_Type(2)!="Fire")
                        {
                           m->setFirem();
                        }
                     }
                     else
                     {
                           m->eraseSm(2);
                     }
                  }
                  else if (i==12)
                  {
                     if(line=="Air")
                     {
                        if(m->getspells_Type(3)!="Air")
                        {
                           m->setAirm();
                        }
                     }
                     else
                     {
                           m->eraseSm(3);
                     }
                   }

                   else if (i==13)
                   {
                     int r=findachar(line,'_');
                     int r2=findachar(line,':');
                     if (r!=-1)
                     {
                       string sub;
                       sub=line.substr(r+1,r2-r-1);
                       string sub2=line.substr(r2+1,line.size()-r2+1);
                       int lvl=stoi(sub2);
                       Weapon jamon(sub,lvl);
                       equip.push_back(jamon);
                     }
                     if (r==-1)
                     {
                         Weapon Juaquin;
                         dynamic_cast<Mage*>(_Teams[I].back())->equipWeapon(-1);
                     }
                  }

                  else if(i==14)
                  {
                      int r=findachar(line,'/');
                      string sub;
                      sub=line.substr(0,r);
                      string sub2=line.substr(r+1,line.size()-r+1);
                      int l=findachar(sub2,'/');
                      string sub3=sub2.substr(l+1,sub2.size()-l-1);
                      sub2=line.substr(r+1,l);
                      int ph=stoi(sub);
                      int pxp=stoi(sub2);
                      int pm=stoi(sub3);
                      _Teams[I].back()->addPotinv("health",ph);
                      _Teams[I].back()->addPotinv("xp",pxp);
                      _Teams[I].back()->addPotinv("mana",pm);

                  }
                 }
                  else if(i>=15)
                  {
                    int r=findachar(line,'_');
                    int r2=findachar(line,':');
                    if (r!=-1)
                    {
                      string sub;
                      sub=line.substr(r+1,r2-r-1);
                      string sub2=line.substr(r2+1,line.size()-r2+1);
                      int lvl=stoi(sub2);
                      Weapon jamon(sub,lvl);
                      int mon=_Teams[I].back()->getinventory_m();
                      _Teams[I].back()->getInventoryDirect()->setMoney(1000);
                      _Teams[I].back()->_store.buy_Item(jamon.getWeaponType(),*_Teams[I].back()->getInventoryDirect());
                      _Teams[I].back()->getInventoryDirect()->setMoney(mon);
                    }
                    if (r==-1)
                    {
                        Weapon Juaquin;
                        dynamic_cast<Mage*>(_Teams[I].back())->equipWeapon(-1);
                    }
                  }

            }
            i++;
        }
     input_f.close();
     return 1;
    }catch (runtime_error &e)
    {
        cout<<e.what()<<endl;
        return 0;
    }
}

void Game::displayList(int team)
{
    for (long unsigned int i=0;i<_Teams[team].size();i++){
        if(dynamic_cast<Warrior*>(_Teams[team][i])!=nullptr){
            cout<<i+1<<". Warrior: ";
        }
        else if(dynamic_cast<Mage*>(_Teams[team][i])!=nullptr){
            cout<<i+1<<". Mage: ";
        }
        else if(dynamic_cast<Archer*>(_Teams[team][i])!=nullptr){
            cout<<i+1<<". Archer: ";
        }
        cout<<_Teams[team][i]->getName()<<"  level: "<<_Teams[team][i]->getLevel()<<"  health: "<<_Teams[team][i]->getHealth()<<endl;
    }
}

int Game::Attack(){
    Character*Attacker=_Teams[_team][_player];
    long unsigned int oponent;
    string option;
    long unsigned int ally;
    int against;
    if(_team==0){against=1;}else{against=0;}
    this->displayList(against);
    int damage;
    int protection=0;
    int match=0;
    do{
        cout<<endl<<"Select oponent: ";
        cin>>oponent;
    }while(oponent<1||oponent>_Teams[against].size());
    --oponent;

    if(dynamic_cast<Warrior*>(Attacker)!=nullptr){                               //getting attackers attack
        damage=dynamic_cast<Warrior*>(Attacker)->getAttack();
    }
    else if(dynamic_cast<Archer*>(Attacker)!=nullptr){
        damage=dynamic_cast<Archer*>(Attacker)->getAttack();
    }
    else if(dynamic_cast<Mage*>(Attacker)!=nullptr){                             //ehan mage choose between spell or attack
        do{
            cout<<"Do you want to use a spell?(1=Yes; 0=No): ";
            cin>>option;
        }while(option!="0"&&option!="1");
        if(option=="0"){
            damage=dynamic_cast<Mage*>(Attacker)->getAttack();
        }
        else if(option=="1"){
            dynamic_cast<Mage*>(Attacker)->display();
            do{
                cout<<"Introduce spell type(exactly as displayed): ";
                cin>>option;
                for (int i=0;i<4;i++){
                    if(option==dynamic_cast<Mage*>(Attacker)->getspells_Type(i)){
                        match=1;
                    }
                }
            }while(match==0);
            match=0;
            if(option!="Earth"&&option!="Air"){damage=0;}
            else{                                                                                                           //if Earth or Air they get another turn
                if(dynamic_cast<Mage*>(Attacker)->getSpells(option,"mana")>dynamic_cast<Mage*>(Attacker)->getMana()){
                    cout<<endl<<"not enough mana!"<<endl;
                    return 0;
                }
                else{
                    if(option=="Earth"){
                        protection=_Teams[against][oponent]->getProtection();
                        _Teams[against][oponent]->setProtection(protection/2);
                    }
                    else{
                        _Teams[against][oponent]->setLevel(_Teams[against][oponent]->getLevel()-1);
                    }
                    if (dynamic_cast<Mage*>(Attacker)->getspells_Type(0)=="non"&&dynamic_cast<Mage*>(Attacker)->getspells_Type(2)=="non"){      //make sure they can choose another another spell apart from air and earth
                        option="0";
                    }
                    else{
                        do{
                            cout<<"Do you want to use a spell?(1=Yes; 0=No): ";
                            cin>>option;
                        }while(option!="0"&&option!="1");
                    }
                    if(option=="0"){
                        damage=dynamic_cast<Mage*>(Attacker)->getAttack();
                    }
                    if (option=="1"){
                        damage=0;
                        do{
                            cout<<"Introduce spell type different from Earth and Air(exactly as displayed): ";
                            cin>>option;
                            if(option!="Earth"&&option!="Air"){
                                for (int i=0;i<4;i++){
                                    if(option==dynamic_cast<Mage*>(Attacker)->getspells_Type(i)){
                                        match=1;
                                    }
                                }
                            }

                        }while(match==0);
                    }
                }

            }

            if(option=="Water"){
                if(dynamic_cast<Mage*>(Attacker)->getSpells(option,"mana")>dynamic_cast<Mage*>(Attacker)->getMana()){
                    cout<<endl<<"not enough mana!"<<endl;
                    return 1;
                }
                else{

                    do{
                        cout<<"Select ally to increase health: ";
                        cin>>ally;
                    }while(ally>_Teams[_team].size());
                    --ally;
                    _Teams[_team][ally]->setHealth(_Teams[_team][ally]->getHealth()+((1+(0.5*(dynamic_cast<Mage*>(Attacker)->getW_type()=="Water Staff")))*dynamic_cast<Mage*>(Attacker)->getSpells(option,"power")));   //Special ability water staff
                }

            }
            else if(option=="Fire"){
                if(dynamic_cast<Mage*>(Attacker)->getSpells(option,"mana")>dynamic_cast<Mage*>(Attacker)->getMana()){
                    cout<<endl<<"not enough mana!"<<endl;
                    return 1;
                }
                else{
                    cout<<endl<<"Attacking "<<Attacker->getName()<<" to "<<_Teams[against][oponent]->getName()<<endl;
                    _Teams[against][oponent]->setHealth(_Teams[against][oponent]->getHealth()-((1+(0.25*(dynamic_cast<Mage*>(Attacker)->getW_type()=="Fire Staff")))*dynamic_cast<Mage*>(Attacker)->getSpells(option,"power")));
                    //Special ability fire staff +0.25 daño fuego
                }
            }
        }
    }
    if(dynamic_cast<Warrior*>(_Teams[against][oponent])!=nullptr){                                                             //calculate the attack and defence
        cout<<endl<<"getdefeW"<<endl;
        damage=dynamic_cast<Warrior*>(_Teams[against][oponent])->getDefence()-damage;
        if(dynamic_cast<Mage*>(Attacker)!=nullptr && dynamic_cast<Mage*>(Attacker)->getW_type()=="Air Staff"){
            dynamic_cast<Warrior*>(_Teams[against][oponent])->setShield(0);
        }
    }
    else if(dynamic_cast<Archer*>(_Teams[against][oponent])!=nullptr){
        damage=dynamic_cast<Archer*>(_Teams[against][oponent])->getDefence()-damage;
    }
    else if(dynamic_cast<Mage*>(_Teams[against][oponent])!=nullptr){
        cout<<endl<<"getdefeM"<<endl;
        damage=dynamic_cast<Mage*>(_Teams[against][oponent])->getDefence()-damage;
        if(dynamic_cast<Mage*>(Attacker)!=nullptr && dynamic_cast<Mage*>(Attacker)->getW_type()=="Air Staff"){
            dynamic_cast<Mage*>(_Teams[against][oponent])->setMana(dynamic_cast<Mage*>(_Teams[against][oponent])->getMana()/2);
        }
    }
    act_action_log(1,oponent,against);
    if(damage<0){                                                                                                      //see if the attack exceededs the defence
        cout<<endl<<"Attacker took out "<<damage<<"ps from the oponent"<<endl;
        Attacker->addXp(-damage/2);
        _Teams[against][oponent]->setHealth(_Teams[against][oponent]->getHealth()+damage);
        if(dynamic_cast<Archer*>(Attacker)!=nullptr&&dynamic_cast<Archer*>(Attacker)->getW_type()=="Epic Bow"){        //speciall bow ability
            cout<<endl<<"Speciall Epic Bow ability extra "<<0.25*damage<<"ps damage"<<endl;
            _Teams[against][oponent]->setHealth(_Teams[against][oponent]->getHealth()+(0.25*damage));
        }
    }
    else{
        cout<<endl<<"No damage recieved"<<endl;
    }
    if(_Teams[against][oponent]->getHealth()<=0){                                                                     //checking dead player
        _Teams[against][oponent]->setHealth(0);
        cout<<_Teams[against][oponent]->getName()<<" died"<<endl;
        act_action_log(2,oponent,against);
        if(against==0){
            addChar_Graveyard_A(_Teams[against][oponent]);
        }
        else{
            addChar_Graveyard_B(_Teams[against][oponent]);
        }
        _Teams[against].erase(_Teams[against].begin()+oponent);             //erases after sending it to the graveyard
    }
    else{

    }
    if (protection>0){_Teams[against][oponent]->setProtection(protection);}
    return 0;
}

int Game::displayMenu(){
    Character*Player=_Teams[_team][_player];
    cout<<"╔════════════╦════════════╦═══════════╦═════════════╦══════════╦════════╗"<<endl<<"║  1.ATTACK  ║   2.SHOP   ║  3.STATS  ║ 4.INVENTORY ║ 5.SWITCH ║ 6.EXIT ║"<<endl<<"╚════════════╩════════════╩═══════════╩═════════════╩══════════╩════════╝"<<endl;
    int option;
    int op1;

    long unsigned int change;
    string item;
    int check;
    do{
        cout<<endl<<"Choose an option: ";
        cin>>option;
    }while((option>6||option<1)&&option!=69);
    switch (option) {
    case 1:{
        int lB = 0;
        int uB = 12;
        srand(time(NULL));
        int dice=lB+rand()%(uB-lB+1);
        cout<<endl<<"     d: "<<dice<<"      a: "<<_Teams[_team][_player]->getAccuracy()<<endl;
        if(dice<=_Teams[_team][_player]->getAccuracy()){
            this->Attack();
        }
        else{
            cout<<endl<<"The attack missed"<<endl;
            act_action_log(3,0,0);
        }
        return 1;
        break;}
    case 2:
        //_Teams[_team][_player]->getInventoryDirect()->setMoney(100);
        cout<<"Do you want to buy(0) or to sell items(1)?"<<endl;
        cin>>op1;
        while(op1!=1 and op1!=0)
        {
            cout<<"Incorrect option,please select a valid one:";
            cin>>op1;
            cout<<endl;
        }
        switch(op1)
        {
            case 0:
                Player->_store.display();
                do{
                    cout<<endl<<"Please enter name of the item as shown, take care of the upper case letters and the black space between words should be written as _ "<<endl<<"What item do you wanna buy?: ";
                    cin>>item;
                    cout<<endl<<item<<endl;
                    check=Player->_store.buy_Item(item,*Player->getInventoryDirect());
                }while(check==-1);
                if(check==45){
                    Player->getInventory().subsMoney(check);
                    dynamic_cast <Mage*>(Player)->setWaterm();
                    dynamic_cast <Mage*>(Player)->setFirem();
                    dynamic_cast <Mage*>(Player)->setEarthm();
                    dynamic_cast <Mage*>(Player)->setAirm();
                    Player->Character::display();
                    return 1;
                }
                if(check==25){
                    if(dynamic_cast <Warrior*>(Player)->getShield()<30){
                        Player->getInventory().subsMoney(check);
                        dynamic_cast <Warrior*>(Player)->setShield(30);
                    }
                }
                if (check==10){
                    int aviable=15-dynamic_cast<Archer*>(Player)->getArrows();
                    if(aviable>0){
                        int amount;
                        do{
                            cout<<"How many Arrows?: ";
                            cin>>amount;
                            if(amount>aviable){
                                cout<<endl<<"You can buy a maximum of "<<aviable<<" Arrows"<<endl;
                            }
                            else if((amount*check)>Player->getinventory_m()){
                                cout<<endl<<"You do not have that much money"<<endl;
                            }
                        }while(amount<aviable);
                        cout<<"Transaction accepted"<<endl;
                    }
                }
                break;
            case 1:
                int pot;
                long unsigned int ch;
                Player->getInventory().display();
                do{
                    cout<<endl<<"Sell potion(0) or sell weapon (1)? ";
                    cin>>pot;
                }while (pot<0||pot>1);
                cout<<endl<<"Money: "<<Player->getinventory_m()<<endl;
                if(pot==1){
                    do{
                        cout<<endl<<"Enter position: ";
                        cin>>ch;
                        --ch;
                    }while(ch>Player->getInventory().getWeaps().size()-1);
                    if(dynamic_cast<Archer*>(Player)!=nullptr){
                        if(&(*Player->getInventoryDirect()->getWeDirect())[ch]==dynamic_cast<Archer*>(Player)->getEquiped()){
                            dynamic_cast<Archer*>(Player)->equipWeapon(-1);
                        }
                    }
                    if(dynamic_cast<Mage*>(Player)!=nullptr){
                        if(&(*Player->getInventoryDirect()->getWeDirect())[ch]==dynamic_cast<Mage*>(Player)->getEquiped()){
                            dynamic_cast<Mage*>(Player)->equipWeapon(-1);
                        }
                    }
                    if(dynamic_cast<Warrior*>(Player)!=nullptr){
                        for(long unsigned int sale=0;sale<1;sale++){
                            if(&(*Player->getInventoryDirect()->getWeDirect())[ch]==dynamic_cast<Warrior*>(Player)->getEquiped()[sale]){
                                dynamic_cast<Warrior*>(Player)->equipWeapon(-1,sale);
                            }
                        }
                    }
                }
                else if(pot==0){
                    do{
                        cout<<endl<<"Enter position: ";
                        cin>>ch;
                        --ch;
                        if(dynamic_cast<Mage*>(Player)!=nullptr){
                        }
                        else{
                           if(ch==2){ch=-3;}
                        }
                    }while(ch>2);
                }

                Player->_store.sell_Item(pot,ch,(*Player->getInventoryDirect()));
                cout<<endl<<"Money: "<<Player->getinventory_m()<<endl;
                break;
        }
        return 0;
        break;
    case 3:
        Player->Character::display();
        return 0;
        break;
    case 4:
        Player->getInventory().display();
        int use;
        do{
           cout<<endl<<"Exit (0)   Use potion(1)   Equip weapon(2)";
           cin>>use;
        }while(use!=0&&use!=1&&use!=2);
        //usar pocion
        if(use==1){
            string pot;
            do{
                cout<<endl<<"Enter potion type (no uppercase): ";
                cin>>pot;
                if(dynamic_cast<Mage*>(Player)!=nullptr){
                }
                else{
                   if(pot=="mana"){pot="non";}
                }
            }while(pot!="mana"&&pot!="health"&&pot!="xp");
            if(pot=="health"){
                Player->setHealth(100);
            }
            else if(pot=="mana"){
                dynamic_cast<Mage*>(Player)->setMana(100);
            }
            else if(pot=="xp"){
                Player->addXp(60);
            }
        }
        //equipar arma
        else if (use==2){
            long unsigned int weap;
            do{
                cout<<endl<<"Enter weapon position: ";
                cin>>weap;
                --weap;
            }while(weap>(*Player->getInventoryDirect()).getWeDirect()->size()-1);
            if(dynamic_cast<Mage*>(Player)!=nullptr){
                (*dynamic_cast<Mage*>(Player)->getEquiped())->display();
                dynamic_cast<Mage*>(Player)->equipWeapon(weap);
            }
            else if(dynamic_cast<Archer*>(Player)!=nullptr){
                (*dynamic_cast<Archer*>(Player)->getEquiped())->display();
                dynamic_cast<Archer*>(Player)->equipWeapon(weap);
            }
            else{
                int hand;
                for(int i=0;i<2;i++){
                    (*dynamic_cast<Warrior*>(Player)->getEquiped()[i])->display();
                }
                do{
                    cout<<endl<<"Which hand left(0) or right (1): ";
                    cin>>hand;
                }while(hand!=0&&hand!=1);
                dynamic_cast<Warrior*>(Player)->equipWeapon(weap,hand);
            }
        }
        return 0;
        break;
    case 5:
        this->displayList(_team);
        cout<<endl<<"Select a character: ";
        cin>>change;
        while(change<0||change>_Teams[_team].size())
        {
            cout<<endl<<"Incorrect option,please select a valid character: ";
            cin>>change;
            --change;
        }
        _player=change;
        return 0;
    case 6:
        saveProgress();
        saveGraveyard();
        return 3;
        break;
    case 69:
        display_action_log();
        break;
    default:
        break;
    }
    return 0;
}

void Game::hether()
{
    cout<<"╔════════════╗"<<endl<<"║  RPG GAME  ║"<<endl<<"╚════════════╝"<<endl;
    cout<<endl<<endl;
}

void Game::initialmenu()
{
    hether();
    cout<<"This is the final proyect for computing systems 1 from David Diaz and Guillermo Lucas"<<endl<<endl;

    cout<<"1)Load Game"<<endl;
    cout<<"2)Create Game"<<endl;
    cout<<endl<<"Please select a option:";
}

void Game::main_code()
{
    initialmenu();
    int op;
    cin>>op;
    cout<<endl;
    while (op!=1 && op!=2)
    {
        cout<<endl<<"Incorrect choice,please select a valid one:"<<endl;
        cin>>op;
    }
    switch (op)
    {
        case 1:
    {
        cout<<"Please insert the name of the archive containing the alive characters(don't forget the .txt extension)"<<endl;
               string input;
               cin>>input;
               int rtv=loadGame(input);
               if (rtv==1)
               {
                   cout<<"Game loaded succesfully"<<endl;
               }
               if (rtv==0)
               {
                   cout<<"Your game couldn't be loaded,do you want to try another time?(y/n)"<<endl;
                   char op1;
                   cin>> op1;
                   while (op1!='y' and op1!='Y' and op1!='n' and op1!='N')
                   {
                       cout<<"Incorrect choice,please select a valid one"<<endl;
                       cin>> op1;
                   }
                   if (op1=='y' or op1=='Y')
                   {
                       cout<<"Please insert the name of the archive(don't forget the .txt extension)"<<endl;
                       cin>>input;
                       int rtv2=loadGame(input);
                       if (rtv2==1)
                       {
                           cout<<"Game loaded succesfully"<<endl;
                       }
                       if (rtv2==0)
                       {
                            system("clear");
                            cout<<"Your game couldn't be loaded,initializing character creator"<<endl;
                            create_teams();
                            break;
                       }
                   }
               }
               cout<<"Please insert the name of the archive containing the dead characters(don't forget the .txt extension)"<<endl;
                      string input2;
                      cin>>input2;
                      rtv=loadGraveyard(input2);
                      if (rtv==1)
                      {
                          cout<<"Graveyard loaded succesfully"<<endl;
                      }
                      if (rtv==0)
                      {
                          cout<<"Your graveyard couldn't be loaded,do you want to try another time?(y/n)"<<endl;
                          char op1;
                          cin>> op1;
                          while (op1!='y' and op1!='Y' and op1!='n' and op1!='N')
                          {
                              cout<<"Incorrect choice,please select a valid one"<<endl;
                              cin>> op1;
                          }
                          if (op1=='y' and op1=='Y')
                          {
                              cout<<"Please insert the name of the archive(don't forget the .txt extension)"<<endl;
                              cin>>input;
                              int rtv2=loadGame(input);
                              if (rtv2==1)
                              {
                                  cout<<"Game loaded succesfully"<<endl;
                              }
                              if (rtv2==0)
                              {
                                   cout<<"Your graveyard couldn't be initialized,the game will begin without it"<<endl;
                              }
                          }
                      }

            break;
    }
        case 2:cout<<"Initializing character creator"<<endl;
               create_teams();
            break;
    }
    act_action_log(5,0,0);
    system("clear");//como el clear de matlab
    show_teams();
    randomize_turn();
    do
    {
        displayList(_team);
        long unsigned int player;
        cout<<endl<<"Select a character: ";
        cin>>player;
        while(player<1||player>_Teams[_team].size())
        {
            cout<<endl<<"Incorrect option,please select a valid character: ";
            cin>>player;
        }
        _player=player-1;
        int team=_team;
        do
        {
            rtv3=displayMenu();
            if (rtv3==1)
            {

                change_turn();
            }
            if (rtv3==3){
                break;
            }
        }
        while(team==_team);
        if (rtv3==3){
            break;
        }
    }
    while (_Teams[0].size()!=0 and _Teams[1].size()!=0);
    change_turn();
    system("clear");
    if (_Teams[0].size()!=0&&rtv3!=3)
    {
        cout<<"Team A is the winner"<<endl;
        act_action_log(6,0,0);
    }
    if (_Teams[1].size()!=0&&rtv3!=3)
    {
        cout<<"Team B is the winner"<<endl;
        act_action_log(6,0,0);
    }

    saveProgress();
    saveGraveyard();
}

void Game::show_teams()
{
    cout<<"TEAM A:"<<endl<<endl;
    _team=0;
    displayTeam();
    cout<<"TEAM B:"<<endl<<endl;
    _team=1;
    displayTeam();
}

void Game::randomize_turn()
{
    int lB = 0;
    int uB = 1;
    srand(time(NULL));
    _team=lB+rand()%(uB-lB+1);
    switch (_team)
    {
        case 0:cout<<endl<<endl<<"First turn goes to Team A"<<endl;
            break;
        case 1:cout<<endl<<endl<<"First turn goes to Team B"<<endl;
            break;
    }
}

void Game::change_turn()
{
    switch (_team)
    {
        case 0:_team=1;
            break;
        case 1:_team=0;
            break;
    }
}


void Game::create_teams()
{
    int op;
    cout<<"1-)Create characters with defined progress(you can not chose their atributes)"<<endl;
    cout<<"2-)Create characters with your own stats(xp progress is still aplied)"<<endl;
    cout<<"Option:";
    cin>>op;
    cout<<endl;
    while(op!=1 && op!=2)
    {
        cout<<"Please chose a valid option:";
        cin>>op;
        cout<<endl;
    }
    switch(op)
    {
        case 1:create_n1chars();
            break;
        case 2:create_spchars();
            break;
    }
}


void Game::create_n1chars()
{
    int np;
    cout<<"How many players do you want to inhabit team A?"<<endl;
    cin>>np;
    while(np<=0)
    {
        cout<<"Please,chose a valid number of players:";
        cin>>np;
        cout<<endl;
    }
    for(int j=0;j<np;j++)
    {
        char t;
        cout<<"Do you want your new character to be a Warrior,a Archer or a Mage(W/A/M):";
        cin>>t;
        while(t!='W' and t!='w' and t!='A' and t!='a' and t!='M' and t!='m')
        {
            cout<<"Please,chose a valid option:";
            cin>>t;
            cout<<endl;
        }
        if(t=='W' or t=='w')
        {
            string name;
            cout<<"What will be your character's name:";
            cin>>name;
            cout<<endl;
            Character *w=new Warrior(name);
            addChar_A(w);
        }
        if(t=='A' or t=='a')
        {
            string name;
            cout<<"What will be your character's name:";
            cin>>name;
            cout<<endl;
            Character *w=new Archer(name);
            addChar_A(w);
        }
        if(t=='M' or t=='m')
        {
            string name;
            cout<<"What will be your character's name:";
            cin>>name;
            cout<<endl;
            Character *w=new Mage(name);
            addChar_A(w);
        }
    }
    cout<<"How many players do you want to inhabit team B?"<<endl;
    cin>>np;
    while(np<=0)
    {
        cout<<"Please,chose a valid number of players:";
        cin>>np;
        cout<<endl;
    }
    for(int j=0;j<np;j++)
    {
        char t;
        cout<<"Do you want your new character to be a Warrior,a Archer or a Mage(W/A/M):";
        cin>>t;
        while(t!='W' and t!='w' and t!='A' and t!='a' and t!='M' and t!='m')
        {
            cout<<"Please,chose a valid option:";
            cin>>t;
            cout<<endl;
        }
        if(t=='W' or t=='w')
        {
            string name;
            cout<<"What will be your character's name:";
            cin>>name;
            cout<<endl;
            Character *w=new Warrior(name);
            addChar_B(w);
        }
        if(t=='A' or t=='a')
        {
            string name;
            cout<<"What will be your character's name:";
            cin>>name;
            cout<<endl;
            Character *w=new Archer(name);
            addChar_B(w);
        }
        if(t=='M' or t=='m')
        {
            string name;
            cout<<"What will be your character's name:";
            cin>>name;
            cout<<endl;
            Character *w=new Mage(name);
            addChar_B(w);
        }
    }
}


void Game::create_spchars()
{
    int np;
    cout<<"How many players do you want to inhabit team A?"<<endl;
    cin>>np;
    while(np<=0)
    {
        cout<<"Please,chose a valid number of players:";
        cin>>np;
        cout<<endl;
    }
    for(int j=0;j<np;j++)
    {
        char t;
        cout<<"Do you want your new character to be a Warrior,a Archer or a Mage(W/A/M):";
        cin>>t;
        while(t!='W' and t!='w' and t!='A' and t!='a' and t!='M' and t!='m')
        {
            cout<<"Please,chose a valid option:";
            cin>>t;
            cout<<endl;
        }
        if(t=='W' or t=='w')
        {
            string name;
            int health;
            int lvl;
            int xp;
            int power;
            int protection;
            int strength;
            int accuracy;
            int money;
            int shield;
            cout<<"What will be your character's name:";
            cin>>name;
            cout<<endl;
            cout<<"What will be your character's hp(0-100):";
            cin>>health;
            while (0>health or health>100)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>health;
            }
            cout<<endl<<"What will be your character's level(1-15):";
            cin>>lvl;
            while (1>lvl or lvl>15)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>lvl;
            }
            cout<<endl<<"What will be your character's xp(0-20):";
            cin>>xp;
            while (0>xp or xp>20)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>xp;
            }
            cout<<endl<<"What will be your character's power(0-30):";
            cin>>power;
            while (0>power or power>30)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>power;
            }
            cout<<endl<<"What will be your character's protection(15-30):";
            cin>>protection;
            while (15>protection or protection>30)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>protection;
            }
            cout<<endl<<"What will be your character's strength(1-15):";
            cin>>strength;
            while (1>strength or strength>15)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>strength;
            }
            cout<<endl<<"What will be your character's accuracy(1-12):";
            cin>>accuracy;
            while (1>accuracy or accuracy>12)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>accuracy;
            }
            cout<<endl<<"What will be your character's money:";
            cin>>money;
            while (0>money)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>money;
            }
            cout<<endl<<"What will be your character's shield(0-30):";
            cin>>shield;
            while (0>shield or shield>30)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>shield;
            }
            Character *w=new Warrior(name,health,accuracy,protection,power,lvl,shield,strength,xp,money);
            addChar_A(w);
        }
        if(t=='A' or t=='a')
        {
            string name;
            int health;
            int lvl;
            int xp;
            int power;
            int protection;
            int accuracy;
            int money;
            int arrows;
            int agility;
            cout<<"What will be you'r character's name:";
            cin>>name;
            cout<<endl;
            cout<<"What will be your character's hp(0-100):";
            cin>>health;
            while (0>health or health>100)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>health;
            }
            cout<<endl<<"What will be your character's level(1-15):";
            cin>>lvl;
            while (1>lvl or lvl>15)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>lvl;
            }
            cout<<endl<<"What will be your character's xp(0-20):";
            cin>>xp;
            while (0>xp or xp>20)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>xp;
            }
            cout<<endl<<"What will be your character's power(1-30):";
            cin>>power;
            while (1>power or power>30)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>power;
            }
            cout<<endl<<"What will be your character's protection(20-40):";
            cin>>protection;
            while (20>protection or protection>40)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>protection;
            }
            cout<<endl<<"What will be your character's agility(1-10):";
            cin>>agility;
            while (1>agility or agility>10)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>agility;
            }
            cout<<endl<<"What will be your character's accuracy(1-12):";
            cin>>accuracy;
            while (1>accuracy or accuracy>12)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>accuracy;
            }
            cout<<endl<<"What will be your character's money:";
            cin>>money;
            while (0>money)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>money;
            }
            cout<<endl<<"What will be your character's arrows(0-15):";
            cin>>arrows;
            while (0>arrows or arrows>15)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>arrows;
            }
            Character *w=new Archer(name,health,accuracy,protection,power,lvl,arrows,agility,xp,money);
            addChar_A(w);
        }
        if(t=='M' or t=='m')
        {
            string name;
            int health;
            int lvl;
            int xp;
            int power;
            int protection;
            int accuracy;
            int money;
            int mana;
            cout<<"What will be you'r character's name:";
            cin>>name;
            cout<<endl;
            cout<<"What will be your character's hp(0-100):";
            cin>>health;
            while (0>health or health>100)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>health;
            }
            cout<<endl<<"What will be your character's level(1-15):";
            cin>>lvl;
            while (1>lvl or lvl>15)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>lvl;
            }
            cout<<endl<<"What will be your character's xp(0-20):";
            cin>>xp;
            while (0>xp or xp>20)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>xp;
            }
            cout<<endl<<"What will be your character's power(50-70):";
            cin>>power;
            while (50>power or power>70)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>power;
            }
            cout<<endl<<"What will be your character's protection(50-60):";
            cin>>protection;
            while (50>protection or protection>60)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>protection;
            }
            cout<<endl<<"What will be your character's mana(0-100):";
            cin>>mana;
            while (0>mana or mana>100)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>mana;
            }
            cout<<endl<<"What will be your character's accuracy(1-12):";
            cin>>accuracy;
            while (1>accuracy or accuracy>12)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>accuracy;
            }
            cout<<endl<<"What will be your character's money:";
            cin>>money;
            while (0>money)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>money;
            }
            Character *w=new Mage(name,health,accuracy,protection,power,lvl,xp,money,mana);
            addChar_A(w);
        }
    }
    cout<<"How many players do you want to inhabit team B?"<<endl;
    cin>>np;
    while(np<=0)
    {
        cout<<"Please,chose a valid number of players:";
        cin>>np;
        cout<<endl;
    }
    for(int j=0;j<np;j++)
    {

        char t;
        cout<<"Do you want your new character to be a Warrior,a Archer or a Mage(W/A/M):";
        cin>>t;
        while(t!='W' and t!='w' and t!='A' and t!='a' and t!='M' and t!='m')
        {
            cout<<"Please,chose a valid option:";
            cin>>t;
            cout<<endl;
        }
        if(t=='W' or t=='w')
        {
            string name;
            int health;
            int lvl;
            int xp;
            int power;
            int protection;
            int strength;
            int accuracy;
            int money;
            int shield;
            cout<<"What will be your character's name:";
            cin>>name;
            cout<<endl;
            cout<<"What will be your character's hp(0-100):";
            cin>>health;
            while (0>health or health>100)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>health;
            }
            cout<<endl<<"What will be your character's level(1-15):";
            cin>>lvl;
            while (1>lvl or lvl>15)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>lvl;
            }
            cout<<endl<<"What will be your character's xp(0-20):";
            cin>>xp;
            while (0>xp or xp>20)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>xp;
            }
            cout<<endl<<"What will be your character's power(1-30):";
            cin>>power;
            while (1>power or power>30)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>power;
            }
            cout<<endl<<"What will be your character's protection(15-30):";
            cin>>protection;
            while (15>protection or protection>30)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>protection;
            }
            cout<<endl<<"What will be your character's strength(1-15):";
            cin>>strength;
            while (1>strength or strength>15)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>strength;
            }
            cout<<endl<<"What will be your character's accuracy(1-12):";
            cin>>accuracy;
            while (1>accuracy or accuracy>12)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>accuracy;
            }
            cout<<endl<<"What will be your character's money:";
            cin>>money;
            while (0>money)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>money;
            }
            cout<<endl<<"What will be your character's shield(0-30):";
            cin>>shield;
            while (0>shield or shield>30)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>shield;
            }
            Character *w=new Warrior(name,health,accuracy,protection,power,lvl,shield,strength,xp,money);
            addChar_B(w);
        }
        if(t=='A' or t=='a')
        {
            string name;
            int health;
            int lvl;
            int xp;
            int power;
            int protection;
            int accuracy;
            int money;
            int arrows;
            int agility;
            cout<<"What will be you'r character's name:";
            cin>>name;
            cout<<endl;
            cout<<"What will be your character's hp(0-100):";
            cin>>health;
            while (0>health or health>100)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>health;
            }
            cout<<endl<<"What will be your character's level(1-15):";
            cin>>lvl;
            while (1>lvl or lvl>15)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>lvl;
            }
            cout<<endl<<"What will be your character's xp(0-20):";
            cin>>xp;
            while (0>xp or xp>20)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>xp;
            }
            cout<<endl<<"What will be your character's power(1-30):";
            cin>>power;
            while (1>power or power>30)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>power;
            }
            cout<<endl<<"What will be your character's protection(20-40):";
            cin>>protection;
            while (20>protection or protection>40)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>protection;
            }
            cout<<endl<<"What will be your character's agility(1-10):";
            cin>>agility;
            while (1>agility or agility>10)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>agility;
            }
            cout<<endl<<"What will be your character's accuracy(1-12):";
            cin>>accuracy;
            while (1>accuracy or accuracy>12)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>accuracy;
            }
            cout<<endl<<"What will be your character's money:";
            cin>>money;
            while (0>money)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>money;
            }
            cout<<endl<<"What will be your character's arrows(0-15):";
            cin>>arrows;
            while (0>arrows or arrows>15)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>arrows;
            }
            Character *w=new Archer(name,health,accuracy,protection,power,lvl,arrows,agility,xp,money);
            addChar_B(w);
        }
        if(t=='M' or t=='m')
        {
            string name;
            int health;
            int lvl;
            int xp;
            int power;
            int protection;
            int accuracy;
            int money;
            int mana;
            cout<<"What will be you'r character's name:";
            cin>>name;
            cout<<endl;
            cout<<"What will be your character's hp(0-100):";
            cin>>health;
            while (0>health or health>100)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>health;
            }
            cout<<endl<<"What will be your character's level(1-15):";
            cin>>lvl;
            while (1>lvl or lvl>15)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>lvl;
            }
            cout<<endl<<"What will be your character's xp(0-20):";
            cin>>xp;
            while (0>xp or xp>20)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>xp;
            }
            cout<<endl<<"What will be your character's power(50-70):";
            cin>>power;
            while (50>power or power>70)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>power;
            }
            cout<<endl<<"What will be your character's protection(50-60):";
            cin>>protection;
            while (15>protection or protection>30)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>protection;
            }
            cout<<endl<<"What will be your character's mana(0-100):";
            cin>>mana;
            while (0>mana or mana>100)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>mana;
            }
            cout<<endl<<"What will be your character's accuracy(1-12):";
            cin>>accuracy;
            while (1>accuracy or accuracy>12)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>accuracy;
            }
            cout<<endl<<"What will be your character's money:";
            cin>>money;
            while (0>money)
            {
                cout<<endl<<"Please chose an acceptable value:";
                cin>>money;
            }
            Character *w=new Mage(name,health,accuracy,protection,power,lvl,xp,money,mana);
            addChar_B(w);
        }

    }
}

//Graveyard functions
void Game::saveGraveyard()
{
    time_t Actual=time(nullptr);
    char Actual_converted[50];
    strftime(Actual_converted, sizeof(Actual_converted), "(%Y-%m-%d__%H:%M)", localtime(&Actual));
    string Actual_converted_str=Actual_converted;
    cout<<endl<<"actual converted "<<Actual_converted<<endl;
    string name_out=n_Out_G+Actual_converted_str+extension;
    try
    {
        ofstream output(name_out);
        if(!output.is_open())
        {
            throw runtime_error("Error:Failure to create an archive");
        }
        for(int n=0;n<2;n++)
        {
            if(n==0)
            {
                output<<"Team A"<<endl;
            }
            if(n==1)
            {
                output<<"Team B"<<endl;
            }
            for(long unsigned int i=0;i<_Graveyard[n].size();i++)
            {
                if(dynamic_cast<Warrior*>(_Graveyard[n][i])!= nullptr)
                {
                   Warrior* w=dynamic_cast<Warrior*>(_Graveyard[n][i]);
                   output<<"Warrior "<<w->getName()<<endl;
                   output<<w->getHealth()<<endl;
                   output<<w->getLevel()<<endl;
                   output<<w->getXp()<<endl;
                   output<<w->getPower()<<endl;
                   output<<w->getProtection()<<endl;
                   output<<w->getAccuracy()<<endl;
                   output<<w->getinventory_m()<<endl;
                   output<<w->getStrength()<<endl;
                   output<<w->getShield()<<endl;
                   for (int i=0;i<2;i++)
                   {
                       output<<w->getW_type(i)<<":"<<w->getW_lvl(i)<<endl;
                   }
                   output<<w->getinventory_ph()<<"/"<<w->getinventory_pxp()<<endl;
                   for (int i=0;i<w->getinventory_W_size();i++)
                   {
                       output<<w->getinventory_W_type(i)<<":"<<w->getinventory_W_lvl(i)<<endl;
                   }
                   output<<"\n"<<endl;
                   output<<"\n"<<endl;
                }
                else if(dynamic_cast<Archer*>(_Graveyard[n][i])!= nullptr)
                {
                    Archer* w=dynamic_cast<Archer*>(_Graveyard[n][i]);
                    output<<"Archer "<<w->getName()<<endl;
                    output<<w->getHealth()<<endl;
                    output<<w->getLevel()<<endl;
                    output<<w->getXp()<<endl;
                    output<<w->getPower()<<endl;
                    output<<w->getProtection()<<endl;
                    output<<w->getAccuracy()<<endl;
                    output<<w->getinventory_m()<<endl;
                    output<<w->getAgility()<<endl;
                    output<<w->getArrows()<<endl;
                    output<<w->getW_type()<<":"<<w->getW_lvl()<<endl;
                    output<<w->getinventory_ph()<<"/"<<w->getinventory_pxp()<<endl;
                    for (int i=0;i<w->getinventory_W_size();i++)
                    {
                        output<<w->getinventory_W_type(i)<<":"<<w->getinventory_W_lvl(i)<<endl;
                    }
                    output<<"\n"<<endl;
                    output<<"\n"<<endl;
                }
                else if(dynamic_cast<Mage*>(_Graveyard[n][i])!= nullptr)
                {
                    Mage* w=dynamic_cast<Mage*>(_Graveyard[n][i]);
                    output<<"Mage "<<w->getName()<<endl;
                    output<<w->getHealth()<<endl;
                    output<<w->getLevel()<<endl;
                    output<<w->getXp()<<endl;
                    output<<w->getPower()<<endl;
                    output<<w->getProtection()<<endl;
                    output<<w->getAccuracy()<<endl;
                    output<<w->getinventory_m()<<endl;
                    output<<w->getMana()<<endl;
                    for (int i=0;i<4;++i)
                    {
                       output<<w->getspells_Type(i)<<endl;
                    }
                    output<<w->getW_type()<<":"<<w->getW_lvl()<<endl;
                    output<<w->getinventory_ph()<<"/"<<w->getinventory_pxp()<<"/"<<w->getinventory_pm()<<endl;
                    for (int i=0;i<w->getinventory_W_size();i++)
                    {
                        output<<w->getinventory_W_type(i)<<":"<<w->getinventory_W_lvl(i)<<endl;
                    }
                    output<<"\n"<<endl;
                    output<<"\n"<<endl;
                }
            }
        }
        output<<"/n";
       output.close();
       _i=0;
    } catch (runtime_error &e)
    {
        cout<<e.what()<<endl;
        if (_i<3)
        {
            _i=_i+1;
            this->saveProgress();
        }
    }
}

int Game::loadGraveyard(string input_graveyard)
{
    try
    {
        string line;
        int I;//0 team a,1 team b
        int i=0;
        int count_ws=0;
        int id=0;
        string name;
        int health;
        int accuracy;
        int protection;
        int power;
        int level;
        int shield;
        int strength;
        int xp;
        int moneh;
        int agility;
        int arrows;
        vector <Weapon> equip;
        ifstream input_f(input_graveyard);
        if (!input_f.is_open())
        {
            throw runtime_error("Error:Failure to open the archive");
        }
        while (getline(input_f,line))
        {
            if (line=="/n")
            {
                count_ws=count_ws+1;
                if (count_ws==2 or count_ws==3)
                {
                    if (count_ws==2)
                    {
                        i=0;
                        id=0;
                        if(_Teams[I].back()!=nullptr)
                        {
                            for (long unsigned int pos=0;pos<_Graveyard[I].back()->getInventory().getWeaps().size();pos++){
                                for (long unsigned int we=0;we<equip.size();we++){
                                    if(equip[we].getWeaponType()==_Graveyard[I].back()->getInventory().getWeaps()[pos]->getWeaponType()){
                                        if (dynamic_cast<Warrior*>(_Graveyard[I].back())!=nullptr){
                                            dynamic_cast<Warrior*>(_Graveyard[I].back())->equipWeapon(pos,we);
                                        }
                                        if (dynamic_cast<Archer*>(_Graveyard[I].back())!=nullptr){
                                            dynamic_cast<Archer*>(_Graveyard[I].back())->equipWeapon(pos);
                                        }
                                        if(dynamic_cast<Mage*>(_Graveyard[I].back())!=nullptr){
                                            dynamic_cast<Mage*>(_Graveyard[I].back())->equipWeapon(pos);
                                        }
                                    }
                                }
                            }
                        }
                        equip.clear();
                      }
                      if(count_ws==3)
                      {
                          input_f.close();
                          return 1;
                      }
                }
                continue;
            }
            if(line!="/n")
            {
                count_ws=0;
            }
            if (i==0)
            {

                if (line=="Team A")
                {
                    I=0;
                    continue;
                }
                else if (line=="Team B")
                {
                    I=1;
                    continue;
                }
                else
                {
                    int r=findachar(line,' ');
                    cout<<endl<<"r:"<<r<<endl;
                    switch (r)
                    {
                        case 7: id=1;
                            break;
                        case 6: id=2;
                            break;
                        case 4: id=3;
                            break;
                        case -1:
                                return 0;
                            break;
                        default: cout<<"smth is wrong"<<endl;
                                return 0;
                   }
                name=line.substr(r+1,line.size()-r+1);
               }
            }
            if (id==1)
            {


                if (0<=i and i<=9)
                {
                    if (i==1)
                    {
                        health=stoi(line);
                    }
                    if (i==2)
                    {
                        level=stoi(line);
                    }
                    if (i==3)
                    {
                        xp=stoi(line);
                    }
                    if (i==4)
                    {
                        power=stoi(line);
                    }
                    if (i==5)
                    {
                        protection=stoi(line);
                    }
                    if (i==6)
                    {
                        accuracy=stoi(line);
                    }
                    if (i==7)
                    {
                        moneh=stoi(line);
                    }
                    if (i==8)
                    {
                        strength=stoi(line);
                    }
                    if (i==9)
                    {
                        shield=stoi(line);
                        Character *load=new Warrior(name,health,accuracy,protection,power,level,shield,strength,xp,moneh);
                        if (I==0)

                        {
                            addChar_A(load);
                        }
                        if (I==1)
                        {
                            addChar_B(load);
                        }

                     }
                  }
                  if (i>9)
                  {
                      if(i==10)
                      {
                          int r=findachar(line,'_');
                          int r2=findachar(line,':');
                          if (r!=-1)
                          {
                            string sub;
                            sub=line.substr(r+1,r2-r-1);
                            string sub2=line.substr(r2+1,line.size()-r2+1);
                            int lvl=stoi(sub2);
                            Weapon jamon(sub,lvl);
                            equip.push_back(jamon);
                          }
                          if (r==-1)
                          {
                              Weapon juaquin;
                              dynamic_cast<Warrior*>(_Graveyard[I].back())->equipWeapon(-1,0);
                          }
                      }
                      if(i==11)
                      {
                          int r=findachar(line,'_');
                          int r2=findachar(line,':');
                          if (r!=-1)
                          {
                            string sub;
                            sub=line.substr(r+1,r2-r-1);
                            string sub2=line.substr(r2+1,line.size()-r2+1);
                            int lvl=stoi(sub2);
                            Weapon jamon(sub,lvl);
                            equip.push_back(jamon);
                          }
                          if (r==-1)
                          {
                              Weapon Juaquin;
                              dynamic_cast<Warrior*>(_Graveyard[I].back())->equipWeapon(-1,1);
                          }
                        }
                      if(i==12)
                      {
                          int r=findachar(line,'/');
                          string sub;
                          sub=line.substr(0,r);
                          string sub2=line.substr(r+1,line.size()-r+1);
                          int ph=stoi(sub);
                          int pxp=stoi(sub2);
                          _Graveyard[I].back()->addPotinv("health",ph);
                          _Graveyard[I].back()->addPotinv("xp",pxp);

                      }
                      if(i>=13)
                      {
                          int r=findachar(line,'_');
                          int r2=findachar(line,':');
                          if (r!=-1)
                          {
                            string sub;
                            sub=line.substr(r+1,r2-r-1);
                            string sub2=line.substr(r2+1,line.size()-r2+1);
                            int lvl=stoi(sub2);
                            Weapon jamon(sub,lvl);
                            int mon=_Graveyard[I].back()->getinventory_m();
                            _Graveyard[I].back()->getInventoryDirect()->setMoney(1000);
                            _Graveyard[I].back()->_store.buy_Item(jamon.getWeaponType(),*_Graveyard[I].back()->getInventoryDirect());
                            _Graveyard[I].back()->getInventoryDirect()->setMoney(mon);
                          }
                      }
                  }
            }
            if (id==2)
            {
                if (0<i and i<=9)
                {
                    if (i==1)
                    {
                        health=stoi(line);
                    }
                    else if (i==2)
                    {
                        level=stoi(line);
                    }
                    else if (i==3)
                    {
                        xp=stoi(line);
                    }
                    else if (i==4)
                    {
                        power=stoi(line);
                    }
                    else if (i==5)
                    {
                        protection=stoi(line);
                    }
                    else if (i==6)
                    {
                        accuracy=stoi(line);
                    }
                    else if (i==7)
                    {
                        moneh=stoi(line);
                    }
                    else if (i==8)
                    {
                        agility=stoi(line);
                    }
                    else if (i==9)
                    {
                        arrows=stoi(line);
                        Character *load=new Archer(name,health,accuracy,protection,power,level,arrows,agility,xp,moneh);
                        if (I==0)

                        {
                            addChar_A(load);
                        }
                        else if (I==1)
                        {
                            addChar_B(load);
                        }

                     }
                  }
                  else if (i>9)
                  {
                    if (i==10)
                    {
                        int r=findachar(line,'_');
                        int r2=findachar(line,':');
                        if (r!=-1)
                        {
                          string sub;
                          sub=line.substr(r+1,r2-r-1);
                          string sub2=line.substr(r2+1,line.size()-r2+1);
                          int lvl=stoi(sub2);
                          Weapon jamon(sub,lvl);
                          equip.push_back(jamon);
                        }
                        if (r==-1)
                        {
                            Weapon Juaquin;
                            dynamic_cast<Archer*>(_Graveyard[I].back())->equipWeapon(-1);
                        }
                    }
                    if(i==11)
                    {
                        int r=findachar(line,'/');
                        string sub;
                        sub=line.substr(0,r);
                        string sub2=line.substr(r+1,line.size()-r+1);
                        int ph=stoi(sub);
                        int pxp=stoi(sub2);
                        _Graveyard[I].back()->addPotinv("health",ph);
                        _Graveyard[I].back()->addPotinv("xp",pxp);

                    }
                }
                    if(i>=12)
                    {
                        int r=findachar(line,'_');
                        int r2=findachar(line,':');
                        if (r!=-1)
                        {
                          string sub;
                          sub=line.substr(r+1,r2-r-1);
                          string sub2=line.substr(r2+1,line.size()-r2+1);
                          int lvl=stoi(sub2);
                          Weapon jamon(sub,lvl);
                          int mon=_Graveyard[I].back()->getinventory_m();
                          _Graveyard[I].back()->getInventoryDirect()->setMoney(1000);
                          _Graveyard[I].back()->_store.buy_Item(jamon.getWeaponType(),*_Graveyard[I].back()->getInventoryDirect());
                          _Graveyard[I].back()->getInventoryDirect()->setMoney(mon);
                        }
                    }

                  }
            if (id==3)
            {
                if (0<i and i<=8)
                {
                    if (i==1)
                    {
                        health=stoi(line);
                    }
                    if (i==2)
                    {
                        level=stoi(line);
                    }
                    if (i==3)
                    {
                        xp=stoi(line);
                    }
                    if (i==4)
                    {
                        power=stoi(line);
                    }
                    if (i==5)
                    {
                        protection=stoi(line);
                    }
                    if (i==6)
                    {
                        accuracy=stoi(line);
                    }
                    if (i==7)
                    {
                        moneh=stoi(line);
                    }
                    if (i==8)
                    {
                        int mana=stoi(line);
                        Character *load=new Mage(name,health,accuracy,protection,power,level,xp,moneh,mana);
                        if (I==0)
                        {
                            addChar_A(load);
                        }
                        if (I==1)
                        {
                            addChar_B(load);
                        }

                     }
                  }
                if (i>=9)
                {

                    Mage *m=dynamic_cast<Mage*>(_Graveyard[I].back());

                    if (i==9)
                  {
                     if(line=="Water")
                     {
                         if(m->getspells_Type(0)!="Water")
                         {
                             m->setWaterm();
                         }

                     }
                     else
                     {
                            m->eraseSm(0);
                     }
                  }
                 else if (i==10)
                  {
                     if(line=="Earth")
                     {
                        if(m->getspells_Type(1)!="Earth")
                        {
                            m->setEarthm();
                        }
                     }
                     else
                     {
                            m->eraseSm(1);
                     }
                  }
                  else if (i==11)
                  {
                     if(line=="Fire")
                     {
                        if(m->getspells_Type(2)!="Fire")
                        {
                           m->setFirem();
                        }
                     }
                     else
                     {
                           m->eraseSm(2);
                     }
                  }
                  else if (i==12)
                  {
                     if(line=="Air")
                     {
                        if(m->getspells_Type(3)!="Air")
                        {
                           m->setAirm();
                        }
                     }
                     else
                     {
                           m->eraseSm(3);
                     }
                   }

                   else if (i==13)
                   {
                     int r=findachar(line,'_');
                     int r2=findachar(line,':');
                     if (r!=-1)
                     {
                       string sub;
                       sub=line.substr(r+1,r2-r-1);
                       string sub2=line.substr(r2+1,line.size()-r2+1);
                       int lvl=stoi(sub2);
                       Weapon jamon(sub,lvl);
                       equip.push_back(jamon);
                     }
                     if (r==-1)
                     {
                         Weapon Juaquin;
                         dynamic_cast<Mage*>(_Graveyard[I].back())->equipWeapon(-1);
                     }
                  }

                  else if(i==14)
                  {
                      int r=findachar(line,'/');
                      string sub;
                      sub=line.substr(0,r);
                      string sub2=line.substr(r+1,line.size()-r+1);
                      int l=findachar(sub2,'/');
                      string sub3=sub2.substr(l+1,sub2.size()-l-1);
                      sub2=line.substr(r+1,l);
                      int ph=stoi(sub);
                      int pxp=stoi(sub2);
                      int pm=stoi(sub3);
                      _Graveyard[I].back()->addPotinv("health",ph);
                      _Graveyard[I].back()->addPotinv("xp",pxp);
                      _Graveyard[I].back()->addPotinv("mana",pm);

                  }
                 }
                  else if(i>=15)
                  {
                    int r=findachar(line,'_');
                    int r2=findachar(line,':');
                    if (r!=-1)
                    {
                      string sub;
                      sub=line.substr(r+1,r2-r-1);
                      string sub2=line.substr(r2+1,line.size()-r2+1);
                      int lvl=stoi(sub2);
                      Weapon jamon(sub,lvl);
                      int mon=_Graveyard[I].back()->getinventory_m();
                      _Graveyard[I].back()->getInventoryDirect()->setMoney(1000);
                      _Graveyard[I].back()->_store.buy_Item(jamon.getWeaponType(),*_Graveyard[I].back()->getInventoryDirect());
                      _Graveyard[I].back()->getInventoryDirect()->setMoney(mon);
                    }
                    if (r==-1)
                    {
                        Weapon Juaquin;
                        dynamic_cast<Mage*>(_Graveyard[I].back())->equipWeapon(-1);
                    }
                  }

            }
            i++;
        }
     input_f.close();
     return 1;
    }catch (runtime_error &e)
    {
        cout<<e.what()<<endl;
        return 0;
    }
}
void Game::display_action_log()
{
    system("clear");
    for(long unsigned int i=0;i<action_log.size();i++)
    {
        cout<<action_log[i]<<endl;
    }
}
