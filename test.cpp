#include <iostream>
//*
#include <sstream>
#include <stdio.h>
#include <string.h>
 //*/

#include <termios.h>
#include <unistd.h>

using namespace std;

int main2(void)
{

    char a;
        /*struct termios term;

        tcgetattr(STDIN_FILENO, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN_FILENO, TCSANOW, &term);
    while(a != '\n'){
        a=getchar();
        cout<<a<<endl;
    }//*/

    //*
    stringstream ss;
    string s;
    string s2;
    int i;
    const char * cs;

    // Here I attempt to set stdin to unbuffered, read directly from the keyboard.

        //
        struct termios term;
        tcgetattr(STDIN_FILENO, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN_FILENO, TCSANOW, &term);
        //

    // I wait and get each key press here, initialise to first keystroke.
    a=getchar();

    // While enter is not pressed, build a complete string.

    while(a != '\n')
    {s=s+a;
    a=getchar();
    ss << a;
    ss >> s2;
    cs = s2.c_str();

    //Here I output the ascii code number each time a key is pressed.
    i=cs[0];
    //cout<< i + 100000;
    cout<<a<<endl;





    ss.clear();
    //sleep(10);

    };
    //*/

    //Restore buffer mode

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);




    return 0;
}