#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using std::cout;
using std::endl;

int main() {
    cout << "============================" << endl;
    
    LinkedList list;

    Node aaron; aaron.s = "Aaron"; aaron.a = 17;
    Node gabby; gabby.s = "Gabby"; gabby.a = 14;
    Node jonah; jonah.s = "Jonah"; jonah.a = 21;
    Node dad; dad.s = "Dad"; dad.a = 100;
    Node mom; mom.s = "Mom"; mom.a = 40;
    Node ross; ross.s = "Ross"; ross.a = 12;
    Node lulu; lulu.s = "Lulu"; lulu.a = 7;

    list.addToStart(aaron);
    list.addToStart(gabby);
    list.addToEnd(jonah);
    list.addToEnd(dad);
    list.insertAtPosition(3, mom);
    list.printList();
    list.removeHead();
    list.printList();
    list.removeTail();
    list.printList();
    list.addToEnd(ross);
    list.addToStart(lulu);
    list.printList();
    list.removeAtIndex(3);
    list.printList();
    list.removeName("Jonah");
    list.printList();
    
    cout << "============================" << endl;
    return 0;
}