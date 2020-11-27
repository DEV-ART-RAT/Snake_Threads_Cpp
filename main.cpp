#include <iostream>
#include "./views/windows_start.cpp"
#include "./views/usermain.cpp"
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

    usermain(&user,&userlist);//ingresando usuario
    flag = startMenu(&user);//obteniendo opcion de menu principal
    startMenuOpc(&user,flag);//opcion de menu principal

    return 0;
};