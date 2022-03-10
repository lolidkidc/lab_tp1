#pragma once

using namespace std;

class Item {
public:
    int data = 0;
    Item* prev = nullptr;
};
class Queue {
    
private:

    Item* last = 0;

protected:

    int size;

public:

    Queue();
    ~Queue();
    Item* getLast();
    int pop();
    void push(int el);
    void print();
    void merge(Queue& Q1);
    void copy(Queue& Q);
    int fun();
    bool isEmpty();
};

