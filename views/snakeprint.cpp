#pragma once

#include <string>
#include <iomanip>
#include <iostream>

#include "./colors.h"
#include "../tools/screenControl.h"


using namespace std;

/**
 * Function that gives general parameters to the begining message
 */
void messageSnake(int col,string linea1[],int linea1size){
    string str;
    col = (col- linea1->size() - 4 )/2;
    str.insert(0, col, ' ');
    for (int i=0; i <linea1size ;i++){
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str << COLOR_BOLDGREEN<<linea1[i]<<RESET << str <<COLOR_BOLDRED<<"*"<<RESET <<endl;

    }
    
}

/**
 * Function used to show a line of message
 */
void messageLine(int col,string linea1){
    string str;
    col = (col- linea1.size() - 4 )/2;
    str.insert(0, col, ' ');
    (linea1.size()%2 != 0)?  
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDWHITE<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<" *"<<RESET <<endl:
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDWHITE<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<"*"<<RESET <<endl;
}

/**
 * Function used to show a line of message with cyan color
 */
void messageLineCYAN(int col,string linea1){
    string str;
    col = (col- linea1.size() - 4 )/2;
    str.insert(0, col, ' ');
    (linea1.size()%2 != 0)?  
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDCYAN<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<" *"<<RESET <<endl:
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDCYAN<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<"*" <<RESET <<endl;
}

/**
 * Function used to show a line of message with magenta color
 */
void messageLineMAGENTA(int col,string linea1){
    string str;
    col = (col- linea1.size() - 4 )/2;
    str.insert(0, col, ' ');
    (linea1.size()%2 != 0)?  
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDMAGENTA<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<" *"<<RESET <<endl:
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDMAGENTA<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<"*" <<RESET <<endl;
}

/**
 * Function used to show a line of message with red color
 */
void messageLineRED(int col,string linea1){
    string str;
    col = (col- linea1.size() - 4 )/2;
    str.insert(0, col, ' ');
    (linea1.size()%2 != 0)?  
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDRED<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<" *"<<RESET <<endl:
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDRED<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<"*" <<RESET <<endl;
}

/**
 * Function used to show a line of message with green color
 */
void messageLineGREEN(int col,string linea1){
    string str;
    col = (col- linea1.size() - 4 )/2;
    str.insert(0, col, ' ');
    (linea1.size()%2 != 0)?  
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDGREEN<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<" *"<<RESET <<endl:
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDGREEN<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<"*" <<RESET <<endl;
}
/**
 * Function that makes the top recursive
 */
// (by drubi)
int messageLineSeccionAux(int col,string linea1,int pos,int extra){
    string str,primerespacio="",ultimoespacio="",imprimir="";int extraMitad=0,extraMitadSobra=0,extrasobrafinal=0;
    // SizeSpaces -> saves spaces quantity to be printed (-1 because of the asterisc printed apart)
    int SizeSpaces=(col-linea1.size())-1;
    //the half can hide a leftover thats why the if
    int mitaSpaces=SizeSpaces/2;
    //Gives spaces quantity
    str.insert(0, mitaSpaces-1, ' ');
    // It won't always fit so we need 
    // half of the 'boxes' leftover to the left
    if(extra>0){
        int extraMitad=extra/2;// cout<<extraMitad;
        //If quantity is an odd number one will be loosed thats why we need it
        int extraMitadSobra=extra%2;// cout<<extraMitadSobra;
        //First extra space to fill the screen
        primerespacio.insert(0, extraMitad, ' ');
        // if its odd we add one if not then zero
        extrasobrafinal=extraMitad+extraMitadSobra;
        ultimoespacio.insert(0,extrasobrafinal, ' ');
    }
    // This switch is needed because the last stretch needs a closing * without exceed the limits
    switch (pos)
    {
    case 0:
        if(SizeSpaces%2==0)
            cout<<COLOR_BOLDRED<<"* "<<RESET<<str <<primerespacio<<COLOR_BOLDWHITE<<  linea1 <<RESET<< str<<" ";    
        else
            cout<<COLOR_BOLDRED<<"* "<<RESET<<str <<primerespacio<<COLOR_BOLDWHITE<<  linea1 <<RESET<< str<<"  ";    
        break;
    case -1:
         if(SizeSpaces%2==0)
            cout<<COLOR_BOLDRED<<"* "<<RESET<<str <<COLOR_BOLDWHITE<<linea1<<RESET<<ultimoespacio<< str<<COLOR_BOLDRED<<"*"<<RESET<<endl;    
        else 
            cout<<COLOR_BOLDRED<<"* "<<RESET<<str <<COLOR_BOLDWHITE<<linea1<<RESET<<ultimoespacio<< str<<COLOR_BOLDRED<<" *"<<RESET<<endl;     
        break;

    default:
        if(SizeSpaces%2==0)
            cout<<COLOR_BOLDRED<<"* "<<RESET<<str <<COLOR_BOLDWHITE<<linea1<<RESET<< str<<" ";    
        else
            cout<<COLOR_BOLDRED<<"* "<<RESET<<str <<COLOR_BOLDWHITE<<linea1<<RESET<< str<<"  ";    
        
        break;
    }
 
}
    
void messageSteep(int col){
    string strl;
    strl.insert(0, col - 4, ' ');
    cout<<COLOR_BOLDRED<<"*"<<strl<<"*"<<RESET<<endl;
}

void messageMargin(int col){
    string strl;
    strl.insert(0, col - 2, '*');
    cout<<COLOR_BOLDRED<<strl<<RESET<<endl;
}

/**
 * Function that prints the SNAKE title
 */
int snakeprint(void) {
    winsize w = screenSize();
    string linea1[] = {
        "=====   ===    ==   =======   ==  ==   =====",
        "||      ||\\\\   ||   ||   ||   || //    ||   ",
        "====    || \\\\  ||   ||===||   |||      =====",
        "   ||   ||  \\\\ ||   ||   ||   || \\\\    ||   " ,
        "=====   ==   ====   ==   ==   ==  ==   =====" 
    };
    messageMargin(w.ws_col);
    messageSteep(w.ws_col);
    messageSnake(w.ws_col,linea1 , 5);
    messageSteep(w.ws_col);
    messageSteep(w.ws_col);
    
    
    return 0;
};