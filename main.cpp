#include <iostream>

#include <unistd.h>
#include <termios.h>

#include "./views/colors.h"
#include "./views/usermain.h"
#include "./tools/gameStruct.h"
#include "./views/windows_start.cpp"
#include "./scene/sceneControler.h"
/* 
Para ejecutar:
g++ -pthread main.cpp -o main && ./main
*/
using namespace std;
struct termios term;

void open_buffer();
void close_buffer();
<<<<<<< HEAD
void loading();
void loadScenes(myGame<nodeuserinfouser>*);
void loadScenes(myGame<nodeuserinfouser>* game){
=======
void cargando();
void cargarEscenarios(myGame<nodeuserinfouser>*);


//funcion en la que se pueden añadir escenarios externos
void cargarEscenarios(myGame<nodeuserinfouser>* game){
>>>>>>> edabbe207694f4de1f2bb01eb41ef6896082baff
    chargeScenes(game,"extra1.csv");//escenario a cargar
    chargeScenes(game,"extra2.csv");//escenario a cargar
    chargeScenes(game,"rubi.csv");//escenario a cargar

}


int main(void) {
<<<<<<< HEAD
    srand(time(NULL));
    myGame<nodeuserinfouser> game;// = new myGame();
    loadScenes(&game);
    
    //game.list=NULL;
    game.user=NULL;
    close_buffer();
    //loading();
    usermain(&game);//ingresando usuario y loading lista
=======
    srand(time(NULL));//se inicia el random
    myGame<nodeuserinfouser> game;// se crea la estructura que contiene elemetos claves del juego
    cargarEscenarios(&game);//se caragan los escenarios externos

    close_buffer();
    usermain(&game);//ingresando usuario y cargando lista
>>>>>>> edabbe207694f4de1f2bb01eb41ef6896082baff

    open_buffer();
    startMenu(&game);//procedemos al menu de inicio
    close_buffer();

    return 0;
};

//elemento necesaeio para poder procesar cada pulsacion sin dar ENTER despues de esta
void open_buffer(){
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
void close_buffer(){
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
void loading(){
    string cargand="loading.";
    string snakeloading="\u2B24";
    for (int i = 0; i < 3; i++)
    {
        CLEAR;
        snakeprint();
        messageLineCYAN(w.ws_col,cargand);
        cargand=cargand+".";
        messageLineCYAN(w.ws_col,"Porfavor no precione ninguna tecla.");
        messageSteep(w.ws_col);
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
        sleep(1);
    }
}