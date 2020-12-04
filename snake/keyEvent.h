#pragma once

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <stdio_ext.h> 

#include "snake.h"
#include "my_snake.h"
#include "../tools/gameStruct.h"

/**
 * Function that gets the event from keyboard anc cleans the screen
*/
void keyboardEvent(char* key, bool* flag){
    cin.clear();
    while (*flag){
        *key=getchar();
    }
    cin.clear();
}

/**Function used to 'listen' from keyboard when playing the game
 * Used as a separated thread 
*/
void keyEventSnake(myGame<nodeuserinfouser>* game){
    //Cleans the input buffer
    cin.clear();
    //Uses a flag to indicate if the game is been played
    while (game->playing)
    {   
        //Uses a flag to prevent this thread from executing with the pause menu
        if(!game->pause){
            //Catches an event from keyboard
            game->key=getchar();
            //If catches the <<enter>> key during the game proceeds to pause it
            if(game->key == '\n'){
                //Rises the flag that pauses the game
                game->pause = true;
            }
            //If detects the end of the game, returns, or well finishes the thread
            if(!game->playing){
                return;
            }
        }
    }
    cin.clear();
}

/** Function employed for some menus to navigate between options
 *  key: contains the key from the keyboard
 *  flag: actual option from menu
 *  loop: a flag to end the while loop
 */
int optionSelectionKey(myGame<nodeuserinfouser>* game, auto menssage,int sizeOption){

    char key; 
    int flag = 1;
    bool loop = true;

    //To correct failure in while
    sleep(0.1);
    
    // Shows the message from menu using a lambda funtion
    menssage(flag,game,sizeOption);

    //Clears the buffer from 'keys' awaiting to be executed
    cin.clear();

    //To correct failure in while
    sleep(0.1);

    while(loop){
        //up:65 down:66 o B left:68 rigth:67
        //gets the code of the key
        key=getchar();
        //checks if <<enter>> key has been pressed
        if( key=='\n'){
            return flag;
        }
        //checks if <<UP>> key has been pressed (direction)
        if(key==65 ){
            if(flag > 1){
                flag--;
            }
        }
        //checks if <<DOWN>> key has been pressed (direction)
        if(  key=='B'){
            if(flag < sizeOption){
                flag++;
            }
        }
        // Shows the message from menu using a lambda funtion
        menssage(flag,game,sizeOption); 

        //To correct failure in while
        sleep(0.01);
    }
    cin.clear();
    return 0;
}

/**
 * Funtion that loads the main menu while the key pressed isn't <<enter>> 
 * key: contains the key pressed
 * loop: flag to stop the while loop
 */
bool enterSelection(myGame<nodeuserinfouser>* game,auto wellcome){
    char key; 
    bool loop = true;
    //Invocates menu
    wellcome(game); 

    //Checks if the key pressed is an <<enter>>
    while(loop){
        key=getchar();
        if( key=='\n'){
            return true;
        }
        else{
            return false;
        }
    }
}
