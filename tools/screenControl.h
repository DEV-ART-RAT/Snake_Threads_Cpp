#pragma once
#include <sys/ioctl.h> 
#include <stdio.h> 

struct winsize w;

winsize screenSize () {
    
    ioctl(0, TIOCGWINSZ, &w);
    if(w.ws_col%2!=0){
        w.ws_col--;
    }
    //printf ("lines %d\n", w.ws_row); 
    //printf ("columns %d\n", w.ws_col); 
    return w; 
}

