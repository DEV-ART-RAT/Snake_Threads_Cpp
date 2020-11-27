#include <string>
#include <iostream>
#include <ostream>
#pragma once
using namespace std;


//importamos funcion de nodo para listas dobles
struct nodeuserinfouser {
    int i;
    string c;

    nodeuserinfouser() {}
    nodeuserinfouser(int _i, string _c) : i(_i), c(_c) {}

    bool operator==(const nodeuserinfouser& r) {
        return this->i == r.i && this->c == r.c;
    }

    bool operator!=(const nodeuserinfouser& r) {
        return this->i != r.i && this->c != r.c;
    }

    string toString() {
        return "{" + to_string(this->i) + ":" + this->c + "}";
    }

    bool comparate(nodeuserinfouser& r,int flag){
        if(flag == 1){
            return this->i >= r.i;
        }
        return this->c >= r.c;
    }

    friend ostream& operator<<(ostream& os, const nodeuserinfouser& p) {
        os << "{" + to_string(p.i) + ":" + p.c + "}";
        return os;
    }
};

template<class T>
struct nodeuser {
    T info;
    nodeuser<T>* next,* prev;

    nodeuser() { next = prev = NULL; }
    nodeuser(T _info) : info(_info) { next = prev = NULL; }
};