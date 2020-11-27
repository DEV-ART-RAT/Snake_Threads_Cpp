#include <iostream>
#include "../user/listdouble.cpp"
#include "../user/nodeuser.h"
#include "../user/readuser.cpp"

using namespace std;
void welcomeuser();
void printUsers();

int usermain(void) {
    doubleLinkeduser<nodeuserinfouser> user;
    int P;
    P=0;
    xx(&user);
    pushBackuser(nodeuserinfouser(P, user), &user);
    welcomeuser();
    printUsers();


    return 0;
};
void printUsers(){
    ifstream data;
    //abrimos el archivo
    data.open("./data/user.csv",ios::in);
    for(string line; getline(data,line);){
        stringstream data(line);
        string puntaje,name;
        int point;
        //damos los datos
        for (int col = 0;getline(data,puntaje,',');col++){
            if(col==0){
                name = puntaje;
                cout<<name<<endl;
            }else
            {
                point = stoi(puntaje);
                cout<<puntaje<<endl;

               // pushBack(T(point,name),list);
            }
        }

    }
    data.close();


}

void welcomeuser(void){
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<"\t\t\t=====   ===    =="   <<"   =======   ==  =="  <<"   ====="   <<endl;
    cout<<"\t\t\t||      ||\\\\   ||" <<"   ||   ||   || // "  <<"   ||"      <<endl;
    cout<<"\t\t\t=====   || \\\\  ||" <<"   ||===||   |||   "  <<"   ====="   <<endl;
    cout<<"\t\t\t   ||   ||  \\\\ ||" <<"   ||   ||   || \\\\ "<<"   ||"      <<endl;
    cout<<"\t\t\t=====   ==   ===="   <<"   ==   ==   ==  =="  <<"   ====="   <<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<"\t\t\t BIENVENIDO USUARIO \n";
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<endl<<endl;
}