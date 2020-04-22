#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using std::cout;
using std::endl;

int main() {
    cout << "============================" << endl;
    
    LinkedList list;

    Node n1; n1.s = "Node n1"; n1.a = 10;
    Node n2; n2.s = "Node n2"; n2.a = 20;
    Node n3; n3.s = "Node n3"; n3.a = 30;
    Node n4; n4.s = "Node n4"; n4.a = 40;
    Node n5; n5.s = "Node n5"; n5.a = 50;
    Node n6; n6.s = "Node n6"; n6.a = 60;
    Node n7; n7.s = "Node n7"; n7.a = 70;

    list.addToStart(n1);
    list.addToStart(n2);
    list.addToEnd(n3);
    list.addToEnd(n4);
    list.insertAtIndex(3, n5);
    
    list.printList();
    
    list.removeHead();
    
    list.printList();
    
    list.removeTail();
    
    list.printList();
    
    list.addToEnd(n6);
    list.addToStart(n7);
    
    list.printList();
    
    list.removeAtIndex(3);
    
    list.printList();
    
    list.removeName("Node n3");
    
    list.printList();
    
    cout << "============================" << endl;
    
    return 0;
}