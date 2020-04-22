#include "LinkedList.h"
#include <string>
#include <iostream>

LinkedList::LinkedList() 
    : head{nullptr}, tail{nullptr} {}

LinkedList::LinkedList(Node &n) {
    Node *newNode = new Node(n);
    newNode->next = nullptr;
    tail = newNode;
    head = newNode;
}

LinkedList::~LinkedList() {
    if(head == nullptr) { return; }
    while(head != tail) {
        removeHead();
    }
    removeHead();
}

void LinkedList::addToStart(Node &n) {
    Node *newNode = new Node(n);
    newNode->next = head;
    if(head == nullptr)
        tail = newNode;
    head = newNode;
}

void LinkedList::addToEnd(Node &n) {
    Node *newNode = new Node(n);
    newNode->next = nullptr;
    if(head == nullptr)
        head = newNode;
    else
        tail->next = newNode;
    tail = newNode;
}

void LinkedList::removeHead() {
    if(head == nullptr) { return; }
    Node *newHead = head->next;
    delete head;
    head = newHead;
}

void LinkedList::removeTail() {
    Node *nextToLast = head;
    while(nextToLast->next != tail)
        nextToLast = nextToLast->next;
    nextToLast->next = nullptr;
    delete tail;
    tail = nextToLast;
}

void LinkedList::removeAtIndex(int index) {
    Node *beforeIndex = head;
    for(int i{0}; i != (index - 1); i++) {
        if(beforeIndex->next == nullptr)
            throw std::runtime_error("The traverser exited the list in the removeAtIndex method and did not find an element with that index");
        beforeIndex = beforeIndex->next;
    }
    Node *atIndex = beforeIndex->next;
    beforeIndex->next = atIndex->next;
    delete atIndex;
}

void LinkedList::removeName(std::string name) {
    Node *beforeName = head;
    while(beforeName->next->s != name) {
        if(beforeName->next == nullptr)
            throw std::runtime_error("Reached the end of the list and didn't find the name, in removeName method");
        beforeName = beforeName->next;
    }
    Node *atName =  beforeName->next;
    beforeName->next = atName->next;
    delete atName;
}

void LinkedList::insertAtIndex(int index, Node &n) {
    Node *newNode = new Node(n);
    Node *beforeIndex = head;
    for(int i{0}; i != (index - 1); i++) {
        if(beforeIndex->next == nullptr)
            throw std::runtime_error("Index out of range in insertAtIndex method");
        beforeIndex = beforeIndex->next;
    }
    newNode->next = beforeIndex->next;
    beforeIndex->next = newNode;
}

void LinkedList::printList() {
    Node *traverser = head;
    if(traverser->next == nullptr) {
        std::cout << traverser->s << " is " << traverser->a << std::endl;
        return;
    }
    while(traverser->next != nullptr) {
        std::cout << traverser->s << " is " << traverser->a << std::endl;
        traverser = traverser->next;
    }
    std::cout << traverser->s << " is " << traverser->a << std::endl;
    std::cout << std::endl;
}