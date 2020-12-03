#include <iostream>
#include "./nodeuser.h"
#include "./node.h"
using namespace std;

/** Function that swaps info of 2 nodes
 */
template<class T>
void swapy(node<T>* a, node<T>* b,node<T>** user) {
    T temp = a->info;
    a->info = b->info;
    b->info = temp;
    if(a == *user){
        *user = b;
    }else if(b == *user){
        *user = a;
    }
}

/** Function that pushes a new node in the back
 */
template<class T>
void pushBack(node<T>** dl, T info) {
    node<T>* n = new node<T>(info);

    if(!*dl){
        *dl = n;
    }else {
        node<T>* aux = *dl;
        while(aux->next)
            aux = aux->next;
        n->prev = aux;
        aux->next = n;
    }
}

//////////////////////QUICKSORT ALGORITHM////////////////////////////

/** Recursive function that calculates the pivot 
 * and distributes the elements of the list
 */
template<class T>
void _quickSort(node<T>* low, node<T>* high,int flag,node<T>** user) {
    if(high && low != high && low != high->next) {
        node<T>* pivot = partition(low, high,flag,user);
        _quickSort(low, pivot->prev,flag,user);
        _quickSort(pivot->next, high,flag,user);
    }
}

/** Function that calculates last node of a list
 */
template<class T>
void quickSort(node<T>* head,int flag, node<T>** user) {
    node<T>* last = lastNode(head);
    _quickSort(head, last,flag,user);
}

/** Function that returns head of a list
 */
template<class T>
node<T>* lastNode(node<T>* head) {
    while(head && head->next)
        head = head->next;
    return head;
}

/** Function that returns the pivot of the list
*/ 
template<class T>
node<T>* partition(node<T>* low, node<T>* high,int flag,node<T>** user) {
    T pivot = high->info;
    node<T>* i = low->prev;

    for(node<T>* j = low; j != high; j = j->next) {
        if(j->info.comparate(pivot,flag)) {
            i = (!i) ? low : i->next;
            swapy(i, j,user);
        }
    }
    i = (!i) ? low : i->next;
    swapy(i, high,user);
    return i;
}

template<class T>
void show(node<T>* list){
    if(list){
        show(list->next);
    }
}