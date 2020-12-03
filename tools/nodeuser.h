#pragma once

#include <string>
#include <ostream>
#include <iostream>
using namespace std;

/**Structure used to create a node of the user info
 */
struct nodeuserinfouser {
    //Properties
    int Points;
    int Points_Save;
    int PointsClasic;
    int coin;
    int Lifes;
    int nivel;
    string name;
    
    //Constructors
    nodeuserinfouser() {}
    nodeuserinfouser(
        int _Points,
        int _Points_Save,
        int _PointsClasic,
        int _coin,
        int _Lifes,
        int _nivel, 
        string _name) :
        Points(_Points),
        Points_Save(_Points_Save),
        PointsClasic(_PointsClasic),
        coin(_coin),
        Lifes(_Lifes),
        nivel(_nivel),
        name(_name) {}

    //Overloads
    bool operator==(const nodeuserinfouser& r) {
        return 
        this->Points == r.Points 
        && this->Points_Save == r.Points_Save 
        && this->PointsClasic == r.PointsClasic
        && this->coin == r.coin
        && this->Lifes == r.Lifes
        && this->nivel == r.nivel
        && this->name == r.name; 
    }

    bool operator!=(const nodeuserinfouser& r) {
        return 
        this->Points != r.Points 
        && this->Points_Save != r.Points_Save 
        && this->PointsClasic == r.PointsClasic
        && this->coin != r.coin
        && this->Lifes != r.Lifes
        && this->nivel != r.nivel
        && this->name != r.name; 
       
    }

    //Methods
    string toString() {
        return 
        "{"  + 
        this->name + 
        ":" 
        +to_string(this->Points) 
        +":" 
        +to_string(this->Points_Save) 
        +":"
        +to_string(this->PointsClasic) 
        +":"
        +to_string(this->coin) 
        +":"
        +to_string(this->Lifes) 
        +":" 
        +to_string(this->nivel)
        + "}";
    }

    bool comparate(nodeuserinfouser& r,int flag){
        if(flag == 1){
            return this->Points >= r.Points;
        }
        if(flag == 2){
            return this->Points_Save >= r.Points_Save;
        }
        if(flag == 3){
            return this->PointsClasic >= r.PointsClasic;
        }
        if(flag == 4){
            return this->coin >= r.coin;
        }
        if(flag == 5){
            return this->Lifes >= r.Lifes;
        }
        if(flag == 6){
            return this->nivel >= r.nivel;
        }if(flag==7){
            return this->name >= r.name;
        }
    }

    friend ostream& operator<<(ostream& os, const nodeuserinfouser& p) {
        os << 
        "{Name: " +p.name +
        ": Points: "+ to_string(p.Points) +
        ": Points_save: "+ to_string(p.Points_Save) +
        ": Points Clasic: "+ to_string(p.PointsClasic) +
        ": Coin:" + to_string(p.coin)+
        ": Lifes:" + to_string(p.Lifes)+
        ": Nivel:" + to_string(p.nivel)
        +"}";
        return os;
    }
};

