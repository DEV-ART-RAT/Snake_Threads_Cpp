#pragma once
#include <string>
#include <iostream>
#include <ostream>
using namespace std;


//importamos funcion de nodo para listas dobles
struct nodeuserinfouser {
    int puntaje;
    int coin;
    string name;
    
    nodeuserinfouser() {}
    nodeuserinfouser(int _puntaje,int _coin, string _name) : puntaje(_puntaje), coin(_coin),name(_name) {}

    bool operator==(const nodeuserinfouser& r) {
        return this->puntaje == r.puntaje && this->name == r.name && this->coin == r.coin;
    }

    bool operator!=(const nodeuserinfouser& r) {
        return this->puntaje != r.puntaje && this->name != r.name && this->coin != r.coin;
    }

    string toString() {
        return "{"  + this->name + ":" + to_string(this->puntaje) +":" +to_string(this->coin)+ "}";
    }

    bool comparate(nodeuserinfouser& r,int flag){
        if(flag == 1){
            return this->puntaje >= r.puntaje;
        }
        if(flag == 2){
            return this->coin >= r.coin;
        }
        return this->name >= r.name;
    }

    friend ostream& operator<<(ostream& os, const nodeuserinfouser& p) {
        os << "{Name: " +p.name +": Puntaje: "+ to_string(p.puntaje) + ": Coin:" + to_string(p.coin)+"}";
        return os;
    }
};

