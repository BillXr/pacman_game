#include "Malfoy.h"
malfoy::malfoy(int y,int x,unsigned char ch):player(y,x,ch){}

malfoy::malfoy(){ch='L';}

malfoy::~malfoy() {}
//malfoy has smart movement to catch diamond,it uses a version of distance vector algorithm,he checks if distance from diamond
//becomes smaller if he move to one direction,if so he moves towards this direction,he is doing this check for all direction
void malfoy::move(object player, vector<vector<char>> & map){
    initDistances(map);
    while(checkDistMap(map))
        calculateDistances(player, map);
    if(dist[y][x - 1] < dist[y][x] && map[y][x - 1] != 'M'){
        move_left(map);

    }
    else if(dist[y][x +1 ] < dist[y][x] && map[y][x + 1] != 'M'){
        move_right(map);
    }
    else if(dist[y - 1][x] < dist[y][x] && map[y - 1][x] != 'M'){
        move_up(map);
    }
    else if(dist[y + 1][x] < dist[y][x] && map[y + 1][x] != 'M')
        move_down(map);
}
//init a map with max values in every position
void malfoy::initDistances(vector<vector<char>> & map){
    dist.clear();
    for(size_t j=0; j<map.size(); j++){
        dist.push_back(vector<int>());
        for(size_t k=0; k<map[0].size(); k++)
            dist[j].push_back(INT_MAX);
    }
}
//only diamond position will have 0 as a value meaning that we can now compare adjacent cells in order to set a distance from diamond
//the object parameter used to know diamond place in map
void malfoy::calculateDistances(object & p, vector<vector<char>> & map){
    dist[p.getY()][p.getX()] = 0;
    for(size_t j=0; j<map.size(); j++)//with each loop we find cells that their adjacent ones have lower values than them
        for(size_t k=0; k<map[j].size(); k++){//we get their value and set ours on +1 [0|1|2|3|INT_MAX|INT_MAX]
            if(map[j][k] != '*' && dist[j][k - 1] < dist[j][k]){
                dist[j][k] = dist[j][k - 1] + 1+2;//by adding more we make malfoy choose vertical lines
            }                                       //instead of horizontal in case of a draw
            if(map[j][k] != '*' && dist[j][k + 1] < dist[j][k]){
                dist[j][k] = dist[j][k + 1] + 1+2;
            }
            if(map[j][k] != '*' && dist[j - 1][k] < dist[j][k]){
                dist[j][k] = dist[j - 1][k] + 1;
            }
            if(map[j][k] != '*' && dist[j + 1][k] < dist[j][k]){
                dist[j][k] = dist[j + 1][k] + 1;
            }
        }
}
//if we have found a path till the diamond we stop, because we dont need to check anymore
bool malfoy::checkDistMap(vector<vector<char>> & map){
    if(dist[y][x] != INT_MAX)
        return false;
    else
        return true;
}

