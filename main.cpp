#include <iostream>
#include "./views/windows_start.cpp"
#include "./user/listdouble.cpp"
#include "./user/nodeuser.h"
#include "./user/readuser.cpp"
using namespace std;

/* 
Para ejecutar:
g++ -pthread main.cpp -o main
./main
*/

int main(void) {
    doubleLinked<nodeinfo> user;
    int P=0;
    xx(&user);
    pushBack(nodeinfo(P, user), &user);

    welcomemain();

    return 0;
};