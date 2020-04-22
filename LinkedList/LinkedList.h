#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "Node.h"
#include <string>
#include <iostream>

class LinkedList {
private:
    Node *head;
    Node *tail;
public:
    LinkedList();
    LinkedList(Node &n);
    ~LinkedList();
    
    void addToStart(Node &n);
    void addToEnd(Node &n);
    void insertAtIndex(int index, Node &n);
    
    void removeHead();
    void removeTail();
    void removeAtIndex(int index);
    void removeName(std::string name);
    
    void printList();
};

#endif // _LINKEDLIST_H_
