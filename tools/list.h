#pragma once

#include <string>
#include <iostream>

#include "node.h"
#include "nodeuser.h"
#include "../scene/nodeScene.h"

/** Function that calculates a double linked list's size
 */
using namespace std;
template < class T>
int sizeAux(node<T>* front){
    if(front) {
        return 1 + sizeAux(front->next);
    }
    return 0;
}

/** Structure to create a double linked list using pointers
 */
template<class T>
struct doubleLinked {
    //Properties
    node<T>* front,* back;

    //Constructor
    doubleLinked () {front = back = NULL;}

    //Methods

    //Adds a new node in the front
    void pushFront(T info){
        node<T>* n = new node<T>;
        n->info = info;
        if(this->front){
            n->next = this->front;
            this->front->prev = n;
        }else
        {
            this->back = n;
        }
        this->front = n;
    }

    //Adds a new node in the back
    void pushBack(T info){
        node<T>* n = new node<T>;
        n->info = info;
        if(this->back){
            n->prev = this->back;
            this->back->next = n;
        }else
        {
            this->front = n;
        }
        this->back = n;
    }

    //removes a node from the front
    node<T>* removeFront(){
        node<T>* n = this->front;
        this->front->next->prev=NULL;
        this->front=this->front->next;
        return n;
    }

    //removes a node from the back
    node<T>* removeBack(){
        node<T>* n = this->back;
        this->back->prev->next=NULL;
        this->back=this->back->prev;
        return n;
    }

    //returns list's size
    int size(){
        return sizeAux(front);
    }
    
};

//Adds a new node in an specific position given
template<class T>
void pushAt(int pos, T info, node<T>** front) {
    node<T>* n = new node<T>;
    n->info = info;
    n->prev = n->next = NULL;
    if(pos == 0) {
        (*front)->prev = n;
        n->next = *front;

        *front = n;

        return;
    }
    int counter = 0;
    node<T>* aux = *front;
    while(counter < pos - 1) {
        aux = aux->next;
        counter++;
    }
    n->prev = aux;
    n->next = aux->next;
    aux->next->prev = n;
    aux->next = n;
}

/** Function that prints a double linked list from beginig
 */
template<class T>
void traverseBegin(node<T>* front) {
    if(front) {
        cout << front->info << "  ";
        traverseBegin(front->next);
    }
    else
        cout << endl;
}


/** Function that prints a double linked list from end
 */
template<class T>
void traverseEnd(node<T>* back) {
    if(back) {
        cout << back->info << "  ";
        traverseEnd(back->prev);
    }
    else
        cout << endl;
}

/** Function that removes last node from a double linked list
 */
template<class T>
int remove(T e, node<T>** front) {
    if(*front) {
        if((*front)->info == e) {
            if(!(*front)->prev) {
                *front = (*front)->next;
                (*front)->prev = NULL;
            }
            else {
                node<T>* prev = (*front)->prev;
                *front = (*front)->next;
                
                if(*front)
                    (*front)->prev = prev;

                prev->next = *front;
            }
            return 1 + remove(e, front);
        }
        else
            return 0 + remove(e, &(*front)->next);
    }
    else
        return 0;
}

/** Function that removes first node from a double linked list
 */
template<class T>
bool removeFirst(T e, node<T>** front) {
    if(*front) {
        if((*front)->info == e) {
            if(!(*front)->prev) {
                *front = (*front)->next;
                (*front)->prev = NULL;
            }
            else {
                node<T>* prev = (*front)->prev;
                *front = (*front)->next;
                
                if(*front)
                    (*front)->prev = prev;

                prev->next = *front;
            }
            return true;
        }
        else
            return false + removeFirst(e, &(*front)->next);
    }
    else
        return false;
}

/** Function that removes a node from a double linked list in a position given
 */
template<class T>
bool removeAt(int current, int pos, node<T>** front) {
    if(*front) {
        if(current == pos) {
            if(!(*front)->prev) {
                *front = (*front)->next;
                (*front)->prev = NULL;
            }
            else {
                node<T>* prev = (*front)->prev;
                *front = (*front)->next;
                
                if(*front)
                    (*front)->prev = prev;

                prev->next = *front;
            }

            return true;
        }
        else
            return false + removeAt(current + 1, pos, &(*front)->next);
    }
    else
        return false;
}

/** Function that removes a node from a double linked list with a conditional
 */
template <class Predicative, class T>
int removeIf(Predicative removeCondition, node<T>** front) {
    if(*front) {
        if(removeCondition((*front)->info)) {
            if(!(*front)->prev) {
                *front = (*front)->next;
                (*front)->prev = NULL;
            }
            else {
                node<T>* prev = (*front)->prev;
                *front = (*front)->next;
                
                if(*front)
                    (*front)->prev = prev;

                prev->next = *front;
            }

            return 1 + removeIf(removeCondition, front);
        }
        else
            return 0 + removeIf(removeCondition, &(*front)->next);
    }
    else
        return 0;
}