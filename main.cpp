#include <iostream>
#include "./views/windows_start.cpp"
#include "./views/usermain.cpp"

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
    node<nodeuserinfouser> user;
    doubleLinked<nodeuserinfouser> userlist;
    
    usermain(&user,&userlist);//ingresando usuario y cargando lista
    
    open_buffer();
    startMenu(&user,&userlist);
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