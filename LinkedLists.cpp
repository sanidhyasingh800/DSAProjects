#include <iostream>
#include "LinkedList/SingleLinkedListWithHeadPointer.h"
#include "LinkedList/SingleLinkedListWithHeadPointer.cpp"
#include "LinkedList/DoublyLinkedListWithHeadTailPointers.h"
#include "LinkedList/DoublyLinkedListWithHeadTailPointers.cpp"
using namespace std;
using namespace LinkedLists;


int main() {
    LinkedLists :: DoublyLinkedListWithHeadTailPointers<int> list;
    list.push_front(5);
    list.push_back(10);
    list.push_back(20);
    list.pop_back();
    list.pop_front();
    list.push_front(5);
    list.push_back(10);
    list.push_back(20);
    list.insertAt(1, 99);
    list.insertAt(0, 999);
    list.printallElements();
    cout << list.size();
}