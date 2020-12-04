#pragma once

#include <stdio.h> 
#include <sys/ioctl.h> 

struct winsize w;

/** Function that calculates screen size
 */
winsize screenSize () {
    
    ioctl(0, TIOCGWINSZ, &w);
    if(w.ws_col%2!=0){
        w.ws_col--;
    }
    if(w.ws_col<60){
        w.ws_col=60;
    }
    return w; 
}

