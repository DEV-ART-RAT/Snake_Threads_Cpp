#pragma once
#include <iostream>
#include "../tools/screenControl.h"
#include <iomanip>
#include <string>
#include "./colors.h"

using namespace std;
void mensageSnake(int col,string linea1[],int linea1size){
    string str;
    col = (col- linea1->size() - 4 )/2;
    str.insert(0, col, ' ');
    for (int i=0; i <linea1size ;i++){
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<  COLOR_BOLDGREEN<<linea1[i]<<RESET << str <<COLOR_BOLDRED<<"*"<<RESET <<endl;

    }
    
}

void mensageLine(int col,string linea1){
    string str;
    col = (col- linea1.size() - 4 )/2;
    str.insert(0, col, ' ');
    (linea1.size()%2 != 0)?  
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDYELLOW<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<" *"<<RESET <<endl:
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDYELLOW<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<"*"<<RESET <<endl;
}
void mensageLineWHITE(int col,string linea1){
    string str;
    col = (col- linea1.size() - 4 )/2;
    str.insert(0, col, ' ');
    (linea1.size()%2 != 0)?  
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDWHITE<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<" *"<<RESET <<endl:
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDWHITE<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<"*" <<RESET <<endl;
}
void mensageLineRED(int col,string linea1){
    string str;
    col = (col- linea1.size() - 4 )/2;
    str.insert(0, col, ' ');
    (linea1.size()%2 != 0)?  
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDRED<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<" *"<<RESET <<endl:
    cout<<COLOR_BOLDRED<<"*"<<RESET<<str <<COLOR_BOLDRED<<  linea1 <<RESET<< str <<COLOR_BOLDRED<<"*" <<RESET <<endl;
}

int mensageLineSeccionAux(int col,string linea1,int pos,int extra){
    string str,primerespacio="",ultimoespacio="",imprimir="";int extraMitad=0,extraMitadSobra=0,extrasobrafinal=0;
    // SizeEspacios -> tiene guardada la cantidad de espacios que se tiene que imprimir (-1 por el asterisco que se imprime aparte)
    int SizeEspacios=(col-linea1.size())-1;
    //la mitad puede esconder un sobrante por lo qe esta el if
    int mitaEspacios=SizeEspacios/2;
    //damos el numero de espacios
    str.insert(0, mitaEspacios-1, ' ');
    // COMO NO SIEMPRE VA A CABER necesitamos lo siguiente:
    // las casillas que sobran ala mitad
    if(extra>0){
        int extraMitad=extra/2;// cout<<extraMitad;
        // si el numero es inpar se va a perder uno por lo cual tambien lo necesotamos
        int extraMitadSobra=extra%2;// cout<<extraMitadSobra;
        //primer espacio extra para que cubra la pantalla
        primerespacio.insert(0, extraMitad, ' ');
        // si no es par agregara uno , sino es 0 
        extrasobrafinal=extraMitad+extraMitadSobra;
        ultimoespacio.insert(0,extrasobrafinal, ' ');
    }
    // Se necesita un switch ya que el ultimo tramo necesita un * de cierre sin pasarse de los caracteres
    switch (pos)
    {
    case 0:
        if(SizeEspacios%2==0)
            cout<<COLOR_BOLDRED<<"* "<<RESET<<str <<primerespacio<<COLOR_BOLDWHITE<<  linea1 <<RESET<< str<<" ";    
        else
            cout<<COLOR_BOLDRED<<"* "<<RESET<<str <<primerespacio<<COLOR_BOLDWHITE<<  linea1 <<RESET<< str<<"  ";    
        break;
    case -1:
         if(SizeEspacios%2==0)
            cout<<COLOR_BOLDRED<<"* "<<RESET<<str <<COLOR_BOLDWHITE<<linea1<<RESET<<ultimoespacio<< str<<COLOR_BOLDRED<<"*"<<RESET<<endl;    
        else 
            cout<<COLOR_BOLDRED<<"* "<<RESET<<str <<COLOR_BOLDWHITE<<linea1<<RESET<<ultimoespacio<< str<<COLOR_BOLDRED<<" *"<<RESET<<endl;     
        break;

    default:
        if(SizeEspacios%2==0)
            cout<<COLOR_BOLDRED<<"* "<<RESET<<str <<COLOR_BOLDWHITE<<linea1<<RESET<< str<<" ";    
        else
            cout<<COLOR_BOLDRED<<"* "<<RESET<<str <<COLOR_BOLDWHITE<<linea1<<RESET<< str<<"  ";    
        
        break;
    }
 
}
    
void mensageSteep(int col){
    string strl;
    strl.insert(0, col - 4, ' ');
    cout<<COLOR_BOLDRED<<"*"<<strl<<"*"<<RESET<<endl;
}

void mensageMargin(int col){
    string strl;
    strl.insert(0, col - 2, '*');
    cout<<COLOR_BOLDRED<<strl<<RESET<<endl;
}
void mensageMarginTableaux1(int col){
    string strl;
    strl.insert(0, col, '-');
    cout<<strl;
}
void mensageMarginTableaux2(int col){
    string strl;
    strl.insert(0, col, '+');
    cout<<strl;
}


int snakeprint(void) {
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    
    string linea1[] = {
        "=====   ===    ==   =======   ==  ==   =====",
        "||      ||\\\\   ||   ||   ||   || //    ||   ",
        "====    || \\\\  ||   ||===||   |||      =====",
        "   ||   ||  \\\\ ||   ||   ||   || \\\\    ||   " ,
        "=====   ==   ====   ==   ==   ==  ==   =====" 
    };
    mensageMargin(w.ws_col);
    mensageSteep(w.ws_col);
    mensageSnake(w.ws_col,linea1 , 5);
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
    
    
    return 0;
};