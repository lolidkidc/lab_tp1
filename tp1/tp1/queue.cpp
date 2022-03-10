#include <iostream>
#include "queue.h"

using namespace std;
Queue::Queue() {size = 0;last = nullptr;}

Queue::~Queue() {
    while (size > 0) {
        Item* temp = last;
        last = temp->prev;
        delete temp;
        size--;
    }
}
Item* Queue::getLast(){ return last; }
int Queue::pop(){
    Item* tmp = last;
    int deldata = 0;
    
    if (tmp->prev == nullptr){
        deldata = tmp->data;
        delete last;
        last = nullptr;
        size--;
    }
    else { while (tmp->prev->prev != nullptr) {tmp = tmp->prev; }

        deldata = tmp->prev->data;
        delete tmp->prev;
        tmp->prev = nullptr;
        size--;
    }
    return deldata;
}

void Queue::push(int el){

    Item* new_Item = new Item;
    new_Item->prev = last;
    last = new_Item;
    last->data = el;
    size++;
}

void Queue::print(){

    Item* tmp = last;
    while (tmp->prev != nullptr){

        cout << tmp->data << " --> ";
        tmp = tmp->prev;
    }
    cout << tmp->data << endl;
}
void Queue::copy(Queue& Q) {

    int* buff = new int[Q.size];
    Item* el_queue = Q.last;

    for (int i = Q.size - 1; i >= 0; i--) {
        buff[i] = el_queue->data;
        el_queue = el_queue->prev;
    }

    for (int i = 0; i < Q.size; i++){this->push(buff[i]);}

    delete[] buff;
}

void Queue::merge(Queue& Q1) {

    int* buff1 = new int[Q1.size];
    Item* el_queue1 = Q1.last;

    for (int i = Q1.size - 1; i >= 0; i--){
        buff1[i] = el_queue1->data;
        el_queue1 = el_queue1->prev;
    }

    for (int i = 0; i < Q1.size; i++)
    {
        this->push(buff1[i]);
    }

    delete[] buff1;
    cout << "Queues was successfully merged!" << endl;
}
int Queue::fun() {
    Item* last = this->getLast();
    int sum = 0;

    if (size == 0)
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
        while (last != nullptr) {
            sum += last->data;
            last = last->prev;
        }

        sum /= size;
        last = this->getLast();
    }
    return sum;
}

bool Queue::isEmpty() { return ( size == 0 ? true : false ); }
