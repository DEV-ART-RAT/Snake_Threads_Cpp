#include "nodeuser.h"
#include <iostream>
#include <string>

using namespace std;
template<class T>
//struct de la lista
struct doubleLinkeduser {
    node<T>* front,* back;
    doubleLinkeduser () {
        front = back = NULL;
    }
};
//template ya que es tipo nodo
template<class T>
void pushFront(T info, doubleLinkeduser<T>* dl) {
    //verificamos si tiene a alguien enfrente , sino es porque es el primero
    node<T>* n = new node<T>;
    n->info = info;
    n->prev = NULL;
    if(!dl->front) {
        dl->front = dl->back = n;
        n->prev = n->next = NULL;
        return;
    }
    dl->front->prev = n;
    n->next = dl->front;
    dl->front = n;
}

template<class T>
void pushBack(T info, doubleLinkeduser<T>* dl) {
    //Verificamos como siempre si tiene a a alguien
    node<T>* n = new node<T>;
    n->info = info;
    n->next = NULL;
    if(!dl->front) {
        dl->front = dl->back = n;
        n->prev = n->next = NULL;
        return;
    }
    n->prev = dl->back;
    dl->back->next = n;
    dl->back = n;
}

template<class T>
void pushAtuser(int pos, T info, node<T>** front) {
    //para push en una posicion
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

template<class T>
void traverseBeginuser(node<T>* front) {
    if(front) {
        cout << front->info << "  ";
        traverseBeginuser(front->next);
    }
    else
        cout << endl;
}

template<class T>
void traverseEnduser(node<T>* back) {
    if(back) {
        cout << back->info << "  ";
        traverseEnduser(back->prev);
    }
    else
        cout << endl;
}

template<class T>
int removeuser(T e, node<T>** front) {
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

            return 1 + removeuser(e, front);
        }
        else
            return 0 + removeuser(e, &(*front)->next);
    }
    else
        return 0;
}

template<class T>
bool removeuserFirst(T e, node<T>** front) {
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
            return false + removeuserFirst(e, &(*front)->next);
    }
    else
        return false;
}

template<class T>
bool removeuserAt(int current, int pos, node<T>** front) {
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
            return false + removeuserAt(current + 1, pos, &(*front)->next);
    }
    else
        return false;
}

template <class Predicative, class T>
int removeuserIf(Predicative removeuserCondition, node<T>** front) {
    if(*front) {
        if(removeuserCondition((*front)->info)) {
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

            return 1 + removeuserIf(removeuserCondition, front);
        }
        else
            return 0 + removeuserIf(removeuserCondition, &(*front)->next);
    }
    else
        return 0;
}