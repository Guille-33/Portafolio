#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <ctime>
#include<fstream>
#include <deque>

#include "character.h"

const string n_Out="Saved_game";
const string n_Out_G="Saved_graveyard";
const string n_a_log="Action_log";
const string extension=".txt";

class Game
{
    string action_log_f;
    vector <string> action_log;
    int _i;
    int _player;
    int _team;
    int findachar(string line,char obj);
    vector <vector <Character*> > _Teams;
    deque <deque <Character*> > _Graveyard;
    void create_spchars();
    void create_n1chars();
    int rtv3;
public:
    Game();
    ~Game(){}
    void addChar_A(Character *C){_Teams[0].push_back(C);}
    void addChar_B(Character *C){_Teams[1].push_back(C);}
    void displayTeam();
    void saveProgress();
    int loadGame(string input);
    int displayMenu();
    void hether();
    int Attack();
    void displayList(int team);
    void act_action_log(int op, int deff_c, int deff_i);
    void initialmenu();
    void randomize_turn();
    void change_turn();
    void show_teams();
    void addChar_Graveyard_A(Character *C){_Graveyard[0].push_back(C);}
    void addChar_Graveyard_B(Character *C){_Graveyard[1].push_back(C);}
    void saveGraveyard();
    int loadGraveyard(string input_graveyard);
    void create_teams();
    void display_action_log();
    void main_code();
};

#endif // GAME_H
