#include <termios.h>
#include <unistd.h>

#include <stdio.h>//getChar()
#pragma once


void keyboardEvent(char* key, bool* flag){
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    while (*flag)
    {
        *key=getchar();
    }
    


    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

/* Thread
void myThreadTwo(int b){
    for (int i = 0 ; i  < b; i++){
        cout<<"thread two "<<i<<endl;
        sleep(2);
    }
}
//*/