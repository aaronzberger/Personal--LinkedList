#include "LinkedList.h"
#include <string>
#include <iostream>

LinkedList::LinkedList() 
    : head{nullptr}, tail{nullptr} {}

LinkedList::LinkedList(Node &n) {
    tail = head = &n;
    head->next = nullptr;
}

LinkedList::~LinkedList() {
    if(head == nullptr) { return; }
    while(head != tail) {
        removeHead();
    }
    removeHead();
    //might not work with 0 elements
}

void LinkedList::addToStart(Node &n) {
    Node *temp = &n;
    temp->next = head;
    if(head == nullptr)
        tail = temp;
    head = temp;
}

void LinkedList::addToEnd(Node &n) {
    Node *temp = &n;
    temp->next = nullptr;
    if(head == nullptr)
        head = temp;
    else
        tail->next = temp;
    tail = temp;
}

void LinkedList::removeHead() {
    if(head == nullptr) { return; }
    Node *temp = head->next;
    head = temp;
}

void LinkedList::removeTail() {
    Node *prev = head;
    while(prev->next != tail)
        prev = prev->next;
    prev->next = nullptr;
    tail = prev;
}

void LinkedList::removeAtIndex(int index) {
    //no error checking that index is in range
    Node *prev = head;
    for(int i{0}; i != (index-1); i++)
        prev = prev->next;
    Node *temp = prev->next;
    prev->next = temp->next;
}

void LinkedList::removeName(std::string name) {
    Node *prev = head;
    while(prev->next->s != name)
        prev = prev->next;
    Node *temp =  prev->next;
    prev->next = temp->next;
    
}

void LinkedList::insertAtPosition(int index, Node &n) {
    Node *prev = head;
    for(int i{0}; i != (index-1); i++)
        prev = prev->next;
    Node *temp = &n;
    temp->next = prev->next;
    prev->next = temp;
}

void LinkedList::printList() {
    Node *temp = head;
    if(temp->next == nullptr) {
        std::cout << temp->s << " is " << temp->a << std::endl;
        return;
    }
    while(temp->next != nullptr) {
        std::cout << temp->s << " is " << temp->a << std::endl;
        temp = temp->next;
    }
    std::cout << temp->s << " is " << temp->a << std::endl;
    std::cout << std::endl;
}