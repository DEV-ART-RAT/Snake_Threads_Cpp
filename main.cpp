#include <iostream>
#include "./views/windows_start.cpp"
#include "./views/usermain.cpp"

#include <termios.h>
#include <unistd.h>


using namespace std;

/* 
Para ejecutar:
g++ -pthread main.cpp -o main
./main
*/

int main(void) {
    node<nodeuserinfouser> user;
    doubleLinked<nodeuserinfouser> userlist;
    int flag = 0;
    usermain(&user,&userlist);//ingresando 
    

    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    flag = startMenu(&user);//obteniendo opcion de menu principal
    startMenuOpc(&user,flag);//opcion de menu principal

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    return 0;
};