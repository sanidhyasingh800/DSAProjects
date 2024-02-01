#include <iostream>
#include "LinkedList/SingleLinkedListWithHeadPointer.h"
#include "LinkedList/SingleLinkedListWithHeadPointer.cpp"
using namespace std;
using namespace LinkedLists;


int main() {
    LinkedLists :: SingleLinkedListWithHeadPointer<int> list;
    list.push_front(5);
    list.push_back(10);
    list.push_back(20);
    // list.pop_back();
    // list.pop_front();
    // list.push_front(5);
    // list.push_back(10);
    // list.push_back(20);
    list.printAllElements();
    list.reverseList();
    list.printAllElements();
}