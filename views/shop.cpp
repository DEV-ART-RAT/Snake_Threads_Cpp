#include <iostream>
#include <termios.h>
#include <unistd.h>

//#include "../snake/clear.cpp"
//#include "../snake/matriz.cpp"
#include "../snake/my_snake.h"
#include "../tools/gameStruct.h"
//#include "./windows_start.cpp"
using namespace std;

auto mensajeShop = [](int opc,node<nodeuserinfouser>* userdata) { 
    CLEAR;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<"\t\t\t=====   ===    =="   <<"   =======   ==  =="  <<"   ====="   <<endl;
    cout<<"\t\t\t||      ||\\\\   ||" <<"   ||   ||   || // "  <<"   ||"      <<endl;
    cout<<"\t\t\t=====   || \\\\  ||" <<"   ||===||   |||   "  <<"   ====="   <<endl;
    cout<<"\t\t\t   ||   ||  \\\\ ||" <<"   ||   ||   || \\\\ "<<"   ||"      <<endl;
    cout<<"\t\t\t=====   ==   ===="   <<"   ==   ==   ==  =="  <<"   ====="   <<endl;
    cout<<endl<<endl;

    cout<<"Points: "<<userdata->info.puntaje<<endl;
    cout<<"Coins: "<<userdata->info.coin<<endl;
    //cout<<"Lifes: "<<snake->lifes<<endl;
    cout<<"\t\t\t\t\t"<<((opc==1)?"*":" ")<<" Vida Extra (5 monedas) "<<((opc==1)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==2)?"*":" ")<<" Potenciar puntaje x2 (20 monedas) "<<((opc==2)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==3)?"*":" ")<<" Potenciar puntaje x3 (30 monedas) "<<((opc==3)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==4)?"*":" ")<<"  Regresar "<<((opc==4)?"*":"");
    cout<<endl<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
};

int startMenuAux(node<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* game);
int shopMenu(myGame<nodeuserinfouser>* game);

void boostPointsx2(node<nodeuserinfouser>* userdata, bool x2boosted, bool x3boosted){
	if(!x2boosted && !x3boosted && userdata->info.coin >= 20){
		x2boosted = true;
        userdata->info.coin -= 20;
		cout<<"Puntaje potenciado x2"<<endl;
	}else if(x2boosted || x3boosted){
		cout<<"Un potenciador ya habia sido activado"<<endl;
	} else {
		cout<<"Monedas insuficientes"<<endl;
    }
}

void boostPointsx3(node<nodeuserinfouser>* userdata, bool x2boosted, bool x3boosted){
	if(!x2boosted && !x3boosted && userdata->info.coin >=30){
		x3boosted = true;
        userdata->info.coin -= 30;
		cout<<"Puntaje potenciado x3"<<endl;
	}else if(x2boosted || x3boosted){
		cout<<"Un potenciador ya habia sido activado"<<endl;
	} else {
		cout<<"Monedas insuficientes"<<endl;
    }
}

void buyLife(node<nodeuserinfouser>* userdata){
    if(userdata->info.coin >= 5){
        userdata->info.coin -= 5;
       // userdata->lifes++;
        cout<<"Vida comprada"<<endl;
    } else {
        cout<<"Monedas insuficientes"<<endl;
    }
}



int shopMenuAux(myGame<nodeuserinfouser>* game,int flag){

    //mySnake snake = mySnake();

    bool x2Boosted = false, x3Boosted = false; //Espero que temporalmente aqui
    switch (flag) {
        case 1:
            buyLife(game->user);
            //sleep(1);
            //shopMenu(userdata,userlist);
            break;
        case 2:
            boostPointsx2(game->user, x2Boosted, x3Boosted);
            break;
        case 3:
            boostPointsx3(game->user, x2Boosted, x3Boosted);
            //sleep(1);
            //shopMenu(flag, userdata);
            break;
        case 4:
            //welcomemain(userdata);
            //startMenuOpc(userdata,startMenu(userdata,userlist),userlist);
            return 0;
        default:
            break;
    }
    sleep(1);
    shopMenu(game);

    return 0;
}

int shopMenu(myGame<nodeuserinfouser>* game){
    return shopMenuAux(game,startMenuAux(game->user,mensajeShop,4));
}








