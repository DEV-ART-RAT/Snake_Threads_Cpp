#include <iostream>

#include <unistd.h>
#include <termios.h>

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
void cargarEscenarios(myGame<nodeuserinfouser>*);
void cargarEscenarios(myGame<nodeuserinfouser>* game){
    chargeScenes(game,"extra1.csv");//escenario a cargar
    chargeScenes(game,"extra2.csv");//escenario a cargar
    //chargeScenes(game,"extra1.csv");//escenario a cargar
    //cout<<"escenes:"<<endl;
    //traverseBegin(game->sceneList.front->info.front);

    //game.scenesListContainer.pushBack(game.scenesList);
    //cout<<"total: "<<game->sceneList.size()<<"intrucciones 1:"<<game->sceneList.back->info.size();
    //cout<<"push enter";
    //cin.get();

}


int main(void) {
    srand(time(NULL));
    myGame<nodeuserinfouser> game;// = new myGame();
    cargarEscenarios(&game);
    
    //game.list=NULL;
    game.user=NULL;
    close_buffer();
    usermain(&game);//ingresando usuario y cargando lista

    open_buffer();
    startMenu(&game);
    close_buffer();

    return 0;
};

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
