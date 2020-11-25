#include <string>
#include <iostream>
#pragma once
using namespace std;

struct nodeinfo { //nodo con coordenadas matriciales i, j
    int i;
    int j;

    nodeinfo() {}
    nodeinfo(int _i, int _c) : i(_i), j(_c) {}

    bool operator==(const nodeinfo& r) {
        return this->i == r.i && this->c == r.j;
    }

    bool operator!=(const nodeinfo& r) {
        return this->i != r.i && this->c != r.j;
    }

    bool comparate(nodeinfo& r,int flag){
        if(flag == 1){
            return this->i >= r.i;
        }
        return this->c >= r.j;
    }

    friend ostream& operator<<(ostream& os, const nodeinfo& p) {
        os << "{" + to_string(p.i) + ":" + p.j + "}";
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