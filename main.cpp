#include <iostream>
#include "./views/windows_start.cpp"
#include "./views/usermain.h"
#include "./tools/gameStruct.h"

#include <termios.h>
#include <unistd.h>


using namespace std;
struct termios term;

/* 
Para ejecutar:
g++ -pthread main.cpp -o main
./main
*/
void open_buffer();
void close_buffer();


int main(void) {
    myGame<nodeuserinfouser> game;// = new myGame();
    //game.list=NULL;
    game.user=NULL;
    close_buffer();
    usermain(&game);//ingresando usuario y cargando lista
    
    open_buffer();
    startMenu(&game);
    close_buffer();

    

    return 0;
};


void open_buffer(){
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void close_buffer(){
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}