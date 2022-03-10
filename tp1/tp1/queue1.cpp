#include <iostream>
#include "queue1.h"

int childQueuePrivate::pop() { return Queue::pop(); }
void childQueuePrivate::push(int el) { return Queue::push(el); }
void childQueuePrivate::print() { return Queue::print(); }
void childQueuePrivate::merge(childQueuePrivate& mergeQueue) { return Queue::merge(mergeQueue);}
void childQueuePrivate::copy(childQueuePrivate& mergeQueue) { return Queue::copy(mergeQueue); }
bool childQueuePrivate::isEmpty() { return Queue::isEmpty(); }
int childQueuePrivate::fun() {return Queue::fun(); }

int childQueueProtected::pop() { return Queue::pop(); }
void childQueueProtected::push(int el) { return Queue::push(el); }
void childQueueProtected::print() { return Queue::print(); }
void childQueueProtected::merge(childQueueProtected& mergeQueue) { return Queue::merge(mergeQueue); }
void childQueueProtected::copy(childQueueProtected& mergeQueue) { return Queue::copy(mergeQueue); }
bool childQueueProtected::isEmpty() { return Queue::isEmpty(); }
int childQueueProtected::fun() {return Queue::fun(); }
