#pragma once
#include "queue.h"

class childQueuePrivate : private Queue {

    public:
        int pop();
        void push(int el);
        void print();
        void merge(childQueuePrivate& mergeQueue);
        void copy(childQueuePrivate& mergeQueue);
        bool isEmpty();
        int fun();

};

class childQueueProtected : protected Queue {

    public:
        int pop();
        void push(int el);
        void print();
        void merge(childQueueProtected& mergeQueue);
        void copy(childQueueProtected& mergeQueue);
        bool isEmpty();
        int fun();
};
class childQueuePublic : public Queue {};
