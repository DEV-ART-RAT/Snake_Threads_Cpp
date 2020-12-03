#pragma once

#include <string>
#include <iostream>

using namespace std;

/**Structure used to create a node of info with matricial coordinates
 */
struct nodeinfo {
    //Properties
    int i;
    int j;

    //Constructors
    nodeinfo() {}
    nodeinfo(int _i, int _c) : i(_i), j(_c) {}

    //Overloads
    bool operator==(const nodeinfo& r) {
        return this->i == r.i && this->j == r.j;
    }

    bool operator!=(const nodeinfo& r) {
        return this->i != r.i && this->j != r.j;
    }

    bool comparate(nodeinfo& r,int flag){
        if(flag == 1){
            return this->i >= r.i;
        }
        return this->j >= r.j;
    }

    friend ostream& operator<<(ostream& os, const nodeinfo& p) {
        os << "{" + to_string(p.i) + ":" + to_string(p.j) + "}";
        return os;
    }
};

/**Structure used to create a node that contains another node with info
 */
template<class T>
struct node {
    //Properties
    T info;
    node<T>* next,* prev;

    //Constructors
    node() { next = prev = NULL; }
    node(T _info) : info(_info) { next = prev = NULL; }
};