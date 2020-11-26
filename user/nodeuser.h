#include <string>
#include <iostream>
#pragma once
using namespace std;


//importamos funcion de nodo para listas dobles
struct nodeinfo {
    int i;
    string c;

    nodeinfo() {}
    nodeinfo(int _i, string _c) : i(_i), c(_c) {}

    bool operator==(const nodeinfo& r) {
        return this->i == r.i && this->c == r.c;
    }

    bool operator!=(const nodeinfo& r) {
        return this->i != r.i && this->c != r.c;
    }

    string toString() {
        return "{" + to_string(this->i) + ":" + this->c + "}";
    }

    bool comparate(nodeinfo& r,int flag){
        if(flag == 1){
            return this->i >= r.i;
        }
        return this->c >= r.c;
    }

    friend ostream& operator<<(ostream& os, const nodeinfo& p) {
        os << "{" + to_string(p.i) + ":" + p.c + "}";
        return os;
    }
};

template<class T>
struct node {
    T info;
    node<T>* next,* prev;

    node() { next = prev = NULL; }
    node(T _info) : info(_info) { next = prev = NULL; }
};