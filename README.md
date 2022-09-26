# ncurses_cpp_game

Maze game made with C++ and Ncurses library.

## Story

In this game there is a maze ,where passageways are shown with dots and wall are shown with * asterisk.Inside the map there is a magic diamond,which changes position random moments in time.There are also 2 players Harry Potter and Drago Malfoy, who are trying to catch the diamond before the other does.If potter reaches first the diamond he will be the winner,but if malfoy is the first who get to the diamond,he is going to be the winner.Winner will escape from maze and the other will remain locked inside.

## Gameplay

Main player is controlling Potter with arrow keys in order to reach diamond.Malfoy is moving using AI algorithm,using this he is calculating shortest path towards diamond.His movement checks every position on map and calculate if a single movement to a direction is getting closer to diamond (smaller distance) and if so he moves to this direction.Both players in game check if moves are eligible,because they are not allowed to move to wall.Players are allowed to move up,down,left and right ,no diagonally movement is allowed.Also player can presh space button to remove in the same position,but Malfoy has the opportunity to move.Player can exit game before it ends,pressing escape button.

### Implementation

For the purpose of game i created a main class called Object,with 2 attributes describing position of the map,x and y as coordinates for row and column on maze,and char attribute describing character shown on the map.After that i made 2 new classes Diamond and Player,which both inherit object class because all characters on game (potter,malfoy and diamond) has a place on map,described by 2 coordinates and a character shown on terminal.Diamond class made to manage diamond on game and player class has movement functions,which are been used by both players.First it has boolean check functions for checking if a move to a direction is eligible,because they are not allowed to move towards wall,and if it is these function will return true and allow movement functions to place character in new coordinates and put space in the old place on map.Player class is inherited by 2 classes Potter and Malfoy,which represents two main characters of game.They have as a grandchild attributes for coordinates and character on map from object class and movement function from their father class Player.The most useful class of game is engine class,which controlls loading map from file into memory,show it on terminal,place characters in initial random positions on map,moving diamond,they can not be in the same position at the beginning and checks if someone has reached diamond to be the winner.Diamond movement using counter to count the movements of each player and when counter reach a random number,diamond will spawn in another random coordinates (x and y).To become a player winner of game there is function checking,after every move,if player's coordinates are same as diamond's,also it uses flag to alert system if a player has reached diamond.In every round potter is moving first and malfoy secondly,after both moves ncurses refresh map,in order to seems that players are moving simultaneously. 


