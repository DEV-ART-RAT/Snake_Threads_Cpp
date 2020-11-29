#pragma once
#include <string>
#include <iostream>
#include <ostream>
using namespace std;


//importamos funcion de nodo para listas dobles
struct nodeuserinfouser {
    int puntaje;
    int puntajeContinuar;
    int coin;
    int vidas;
    int nivel;
    string name;
    
    nodeuserinfouser() {}
    nodeuserinfouser(
        int _puntaje,
        int _puntajeContinuar,
        int _coin,
        int _vidas,
        int _nivel, 
        string _name) :
        puntaje(_puntaje),
        puntajeContinuar(_puntajeContinuar),
        coin(_coin),
        vidas(_vidas),
        nivel(_nivel),
        name(_name) {}

    bool operator==(const nodeuserinfouser& r) {
        return 
        this->puntaje == r.puntaje 
        && this->puntajeContinuar == r.puntajeContinuar 
        && this->coin == r.coin
        && this->vidas == r.vidas
        && this->nivel == r.nivel
        && this->name == r.name; 
    }

    bool operator!=(const nodeuserinfouser& r) {
        return 
        this->puntaje != r.puntaje 
        && this->puntajeContinuar != r.puntajeContinuar 
        && this->coin != r.coin
        && this->vidas != r.vidas
        && this->nivel != r.nivel
        && this->name != r.name; 
       
    }

    string toString() {
        return 
        "{"  + 
        this->name + 
        ":" 
        +to_string(this->puntaje) 
        +":" 
        +to_string(this->puntajeContinuar) 
        +":"
        +to_string(this->coin) 
        +":"
        +to_string(this->vidas) 
        +":" 
        +to_string(this->nivel)
        + "}";
    }

    bool comparate(nodeuserinfouser& r,int flag){
        if(flag == 1){
            return this->puntaje >= r.puntaje;
        }
        if(flag == 2){
            return this->puntajeContinuar >= r.puntajeContinuar;
        }
        if(flag == 3){
            return this->coin >= r.coin;
        }
        if(flag == 4){
            return this->vidas >= r.vidas;
        }
        if(flag == 5){
            return this->nivel >= r.nivel;
        }
        return this->name >= r.name;
    }

    friend ostream& operator<<(ostream& os, const nodeuserinfouser& p) {
        os << 
        "{Name: " +p.name +
        ": Puntaje: "+ to_string(p.puntaje) +
        ": Puntaje para continuar: "+ to_string(p.puntajeContinuar) +
        ": Coin:" + to_string(p.coin)+
        ": Vidas:" + to_string(p.vidas)+
        ": Nivel:" + to_string(p.nivel)
        +"}";
        return os;
    }
};

