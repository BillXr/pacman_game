#include "Engine.h"
#include "Potter.h"
#include "Malfoy.h"
#include "Diamond.h"
#include <fstream>
#include <curses.h>
#include <cstdlib>
#include <panel.h>
using namespace std;
int main(int argc, char** argv){
    engine eng;
    potter p;
    malfoy m;
    diamond d;
    int ch;
    string file;
    vector<vector<char>> map;
    if(argc != 2) {   //argument needed is the name of file contains map of the game.
        cout << "You have to give the name of file that contains map,as parameter\n";
        return -1;
    }
    try{
        file=argv[1];
        eng.load_map(map,file);    //loads map
    } catch (exception e) {
        cerr << e.what() << endl;
    }
    setlocale(LC_ALL,"");
    initscr();   //ncurses begins
    start_color();  //starting colors in our terminal
    init_color(1,1000,650,0);    //colors set
    init_pair(1, 1, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_color(3, 700, 0, 0);
    init_pair(3,3,COLOR_BLACK);
    noecho();
    cbreak();
    keypad(stdscr,TRUE);
    curs_set(false);
    if (has_colors() == FALSE) {
        endwin();
        cout<<"Your terminal does not support colors"<<endl;
        exit(1);
    }
    //welcome message to player
    printw ("---WELCOME TO THE GAME---\n\n");
    printw("\n---INSTRUCTIONS---\n\n");
    printw("M: Potter | L: Malfoy | D:Diamond\n");

    printw("Move with the arrow keys | Exit the game with escape\n");
    printw("Get to the diamond first,before Malfoy does\n\n");
    printw("Press a button to start game and have fun...\n");

    getch ();
    clear ();
    refresh();
    //print map,place characters upon it and start game
    eng.begin(map,p,m,d);

    eng.play(map,p,m,d);
    clear();
    return 0;
}
