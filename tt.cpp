#include <iostream>
#include <string>
//#include "node.h"
//#pragma once

using namespace std;

template<class T>
struct node {
    T info;
    node<T>* next,* prev;

    node() { next = prev = NULL; }
    node(T _info) : info(_info) { next = prev = NULL; }
};

template<class T>
struct doubleLinked {
    node<T>* front,* back;

    doubleLinked () {
        front = back = NULL;
    }

    void pushFront(T info){
        node<T>* n = new node<T>;
        n->info = info;
        //n->prev = NULL;
        if(this->front){
            n->next = this->front;
            this->front->prev = n;
        }else
        {
            this->back = n;
        }
        
        this->front = n;
        
    }

    void pushBack(T info){
        node<T>* n = new node<T>;
        n->info = info;
        //n->prev = NULL;
        if(this->back){
            n->prev = this->back;
            this->back->next = n;
        }else
        {
            this->front = n;
        }
        
        this->back = n;
        
    }

    node<T>* removeFront(){
        node<T>* n = this->front;
        this->front->next->prev=NULL;
        this->front=this->front->next;
        return n;
    }
};

/*
template<class T>
void pushFront(T info, doubleLinked<T>* dl) {
    node<T>* n = new node<T>;
    n->info = info;
    n->prev = NULL;

    // If list is empty, then front and back are the same
    // and new prev and next are empty
    if(!dl->front) {
        dl->front = dl->back = n;
        n->prev = n->next = NULL;

        return;
    }

    // Make new next equals front of current list, 
    // make current list front.prev point at new node<T>
    // and alter front pointer
    dl->front->prev = n;
    n->next = dl->front;
    dl->front = n;
}//*/

/*
template<class T>
void pushBack(T info, doubleLinked<T>* dl) {
    node<T>* n = new node<T>;
    n->info = info;
    n->next = NULL;

    // Same as push front
    if(!dl->front) {
        dl->front = dl->back = n;
        n->prev = n->next = NULL;

        return;
    }

    // Make new.prev point at back of complete list,
    // then make back.next point to new node<T>
    // and change back pointer ref
    n->prev = dl->back;
    dl->back->next = n;
    dl->back = n;
}
//*/

template<class T>
void pushAt(int pos, T info, node<T>** front) {
    node<T>* n = new node<T>;
    n->info = info;
    n->prev = n->next = NULL;
    
    // If node<T> is going to be inserted at first pos make it as pushFront
    if(pos == 0) {
        (*front)->prev = n;
        n->next = *front;

        *front = n;

        return;
    }

    int counter = 0;

    // Change to pushing position
    node<T>* aux = *front;
    while(counter < pos - 1) {
        aux = aux->next;
        counter++;
    }

    // Alter references
    n->prev = aux;
    n->next = aux->next;
    aux->next->prev = n;
    aux->next = n;
}

template<class T>
void traverseBegin(node<T>* front) {
    if(front) {
        cout << front->info << "  ";
        traverseBegin(front->next);
    }
    else
        cout << endl;
}

template<class T>
void traverseEnd(node<T>* back) {
    if(back) {
        cout << back->info << "  ";
        // traverseBegin(back->prev); Line with error, wrong recursive call
        traverseEnd(back->prev);
    }
    else
        cout << endl;
}

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


int main(void) {
    doubleLinked<int> dl;
    dl.pushFront(1);
    dl.pushFront(2);
    dl.pushFront(3);
    dl.pushFront(4);
    dl.pushFront(5);
    dl.pushBack(6);
    dl.pushBack(7);
    dl.pushBack(8);
    dl.pushBack(9);
    cout<<"begin"<<endl;
    traverseBegin(dl.front);
    cout<<"back"<<endl;
    traverseEnd(dl.back);

    /*
    pushBack(T(5, 'e'), &dl);
    pushBack(T(6, 'f'), &dl);
    pushBack(T(7, 'g'), &dl);
    cout << "List after pushing elements to back" << endl;
    dl.traverseBeginy();
    
    pushFront(T(3, 'c'), &dl);
    pushFront(T(2, 'b'), &dl);
    pushFront(T(1, 'a'), &dl);
    cout << "List after pushing elements to front" << endl;
    dl.traverseBeginy();

    pushAt(0, T(0, '*'), &dl.front);
    cout << "List after pushing at 0" << endl;
    dl.traverseBeginy();

    pushAt(4, T(4, 'd'), &dl.front);
    cout << "List after pushing at 4" << endl;
    dl.traverseBeginy();
    cout << endl;

    cout << "Deleting 0 with remove: " << remove(T(0, '*'), &dl.front) << endl;
    dl.traverseBeginy();

    cout << "Deleting 4 with removeFirst: " << removeFirst(T(4, 'd'), &dl.front) << endl;
    dl.traverseBeginy();

    cout << "Deleting at pos 1: " << removeAt(0, 1, &dl.front) << endl;
    dl.traverseBeginy();

    cout << "Deleting odds with removeIf: " << removeIf([](T e) -> bool {
        return e.i % 2 != 0;
    }, &dl.front) << endl;
    dl.traverseBeginy();
    //*/

    return 0;
}