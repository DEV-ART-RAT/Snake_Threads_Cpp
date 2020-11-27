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
    nodeuserinfouser userdata;
    usermain(&userdata);
    welcomemain(&userdata);

    return 0;
};