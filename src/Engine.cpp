#include <conio.h>
#include "Engine.h"
engine::engine(){}


//function to load the map into memory, an exception is thrown if there is a problem opening the file
void engine::load_map(vector<vector<char>> &map,string file)
{
    try{
        ifstream input_file(file);
        if(!input_file){
            throw "Problem with opening file,please try again..";
        }
        string str;
        while (getline(input_file, str)){
            vector<char> vec;
            for(char & c : str )
                vec.push_back(c);
            map.push_back(vec);
        }
        input_file.close();
    }catch(const char * msg){
        cout<< msg << endl;
        exit(-1);
    }
}
//function called when the game starts to place the characters in random positions

void engine::begin(vector<vector<char>> & map,potter & p, malfoy & m, diamond &d)
{

    place_potter(map,p,m.getCh(),d.getCh());

    place_malfoy(map,m,p.getCh(),d.getCh());

    place_diamond(map,d,p.getCh(),m.getCh());

}

//the function responsible for moving the diamond, after every move of potter and malfoy a counter is incremented, when the counter reaches a random
//number(everytime this number changes),the diamond changes position and goes to new random coordinates. In the old position it puts the space.
void engine::move_diamond(diamond &d,int counter,vector<vector<char>> & map)
{
    int y,x,newy,newx;
    srand(time(NULL));
    int pos=rand()%map[0].size()+1;
    map[d.getY()][d.getX()]='D';
    if(counter%pos==0){
        do{
            y=rand()%map.size();
            x=rand()%map[0].size();
        }while(map[y][x]!=' ');
        map[d.getY()][d.getX()]=' ';
        d.setY(y);
        d.setX(x);
        map[y][x]=d.getCh();
    }
}

//functions that initially place the players at random locations when starting the game,
// until they check that there is no wall or other character in that location
void engine::place_potter(vector<vector<char>> & map,potter & p,char m,char d)
{
    int x, y;
    srand(time(NULL));
    while(true){
        x = (rand() % map[0].size());
        y = (rand() % map.size());
        if(map[y][x] != '*' && map[y][x] == '.'  && map[y][x] != m && map[y][x] != d){
            p.setX(x);
            p.setY(y);
            map[y][x] = p.getCh();
            break;
        }
    }
}
void engine::place_malfoy(vector<vector<char>> & map,malfoy & m,char p,char d)
{
    int x, y;
    srand(time(NULL));

    while(true){
        x = (rand() % map[0].size());
        y = (rand() % map.size());
        if(map[y][x] != '*'&& map[y][x] == '.'  && map[y][x] != p && map[y][x] != d){
            m.setX(x);
            m.setY(y);
            map[y][x] = m.getCh();
            break;
        }
    }
}
void engine::place_diamond(vector<vector<char>> & map,diamond &d,char p,char m)
{
    int x, y;
    srand(time(NULL));

    while(true){
        x = (rand() % map[0].size());
        y = (rand() % map.size());
        if(map[y][x] != '*' && map[y][x] == '.'&&  map[y][x] != p && map[y][x] != m){
            d.setX(x);
            d.setY(y);
            map[y][x] = d.getCh();
            break;
        }
    }
}

//function to check if a player is on the diamond, checks the coordinates of the objects. If potter is on the same position as diamond
//(x coordinate of potter same as x of diamond and y coordinate of potter same as y of diamond),puts potter in this position and uses flags,bool variables (win=true) to know if potter won.
//Accordingly if malfoy is found together with the diamond, puts malfoy in this position and sets the bool variable loss=true
void engine::check(vector<vector<char>> & map,potter & p, malfoy & m,diamond &d)
{
    if(p.getY()==d.getY() && p.getX()==d.getX()){

        map[p.getY()][p.getX()] = 'M';
        win= true;
        end_game=true;

    }

    if(m.getY()==d.getY() && m.getX()==d.getX()){

        map[m.getY()][m.getX()] = 'L';

        loss = true;
        end_game=true;
    }

}
//function to print the game map to our screen, it also prints the characters with colors and converts the dots to spaces
void engine::show_map(vector<vector<char>> &map)
{

    for(size_t j = 0; j < map.size(); j++){
        for(size_t k = 0; k < map[0].size(); k++){
            if(map[j][k]=='.'){
                map[j][k]=' ';}
            mvwprintw(stdscr,j, k, "%c",map[j][k]);}}


    for(size_t j = 0; j < map.size(); j++){
        for(size_t k = 0; k < map[0].size(); k++){
            if(map[j][k] == 'M'){

                attron(COLOR_PAIR(1));
                mvwprintw(stdscr, j, k, "%c",map[j][k]);
                attroff(COLOR_PAIR(1));
            }
            if(map[j][k] == 'L'){
                attron(COLOR_PAIR(2));
                mvwprintw(stdscr, j, k, "%c",map[j][k]);

                attroff(COLOR_PAIR(2));

            }

            if(map[j][k] == 'D' ){
                attron(COLOR_PAIR(3));
                mvwprintw(stdscr, j, k, "%c",map[j][k]);
                attroff(COLOR_PAIR(3));}

        }
    }
}

//functions to get boolean values of win,loss variables as they are used by functions to know when the game is over and print message to the player
bool engine::get_loss()
{
    return loss;
}
bool engine::get_win()
{
    return win;
}
bool engine::get_end()
{
    return end_game;
}

//move function is called to move the potter based on keyboard input, if the potter moves(returns true in if statement)
//malfoy also moves and the counter increases.If potter remain in the same position or he is trying to move towards wall,the function
//will return false and malfoy will also remain in same position.
void engine::move(vector<vector<char>> & map,potter &p, malfoy & m,diamond &d,int ch)
{
    if(p.move(map,ch))
    {m.move(d,map);
        counter++;
        check(map,p,m,d);

        move_diamond(d,counter,map);
    }


}

//after the map is loaded and the characters are placed on it, the play function is called, where the game is played. It takes input from the keyboard
//and depending on the pressed arrow, it uses switch case to call the move function with the corresponding argument (from the keyboard). After each movement of
//potter moves and malfoy and it is checked through the check, if any player has reached the diamond. Then it is printed (refreshing the map) to show
//that the players move at the same time. Then the diamond also moves according to the counter. Even in the case that a player reaches the diamond,
//use the bool variables and corresponding functions(get_loss,get_win) from play to print a message to the screen and end the game.
//Finally the player can exit the switch case code with the escape key and thus the game will end
void engine::play(vector<vector<char>> & map,potter & p, malfoy & m,diamond &d)
{
    int ch;

    show_map(map);
    do{
        ch=getch();
        switch(ch){

            case KEY_UP:
                move(map,p,m,d,2);
                show_map(map);
                break;
            case KEY_DOWN:
                move(map,p,m,d,4);
                show_map(map);
                break;
            case KEY_LEFT:
                move(map,p,m,d,1);
                show_map(map);
                break;
            case KEY_RIGHT:
                move(map,p,m,d,3);
                show_map(map);
                break;
            case 32:
                move(map,p,m,d,32);
                show_map(map);
                break;
        }

        show_map(map);

        if(get_win()){
            end_game=true;
            cout<<"Congratulations you are the big winner!!!";
            break;
        }
        if(get_loss()){
            end_game=true;
            cout<<"Malfoy is the winner,it's ok try again.";
            break;
        }

        if(ch==27){
            end_game=true;
            cout<<"You left from the game before it ends,hope you like it.";
            break;
        }
        show_map(map);

    }while(ch!=27);
    clear();
    endwin();
    cout<<endl<<"Movement count:"<<counter;

    cout<<endl<<endl<<"\t\t\t======GAME OVER======"<<endl<<endl;


}

