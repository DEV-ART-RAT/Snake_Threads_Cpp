#include <iostream>
#include "../snake/clear.cpp"
#include "./snakeprint.cpp"

//historia by .Drubi
using namespace std;
int history(void) {
    string historia[]={
        "En el princio de la humanidad las personas vivian felizmente",
        "Habian muchos trabajos pero el que mas llamaba la atencion era",
        "Ser mago",
        "Por lo que muchos estudiaban magia negra",
        "En la universidad de los buhos",
        "Eran felices hasta que un dia llego",
        "El Poderoso ENXEL",
        "Que vino a convertir a toda la raza humana en serpientes",
        "Pero llegaste tu para combatirlo",
        "Asi que adelante Gana y vence a Enxel!!!",
        ""
    };
    int i=0;
    CLEAR
    mensageMargin(w.ws_col);
    mensageLineMAGENTA(w.ws_col,"(Presiona Enter para avanzar en la historia)");
    mensageSteep(w.ws_col);
    while(true){
        if(historia[i]!=""){
            mensageLineCYAN(w.ws_col,historia[i]);
            cin.get();
            i++;
        }else
            break;
    }
 
    

    return 0;
};