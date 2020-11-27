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

    usermain(&user,&userlist);
    welcomemain(&user);

    return 0;
};