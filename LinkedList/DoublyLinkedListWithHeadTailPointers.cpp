
#include <iostream>
#include <cassert>
#include "DoublyLinkedListWithHeadTailPointers.h"

// Implementation of a Double Linked List with Head Pointer and Tail Pointer
// Classifications:
// Doubly Linked/ null terminated
//  Head Pointer and Tail Pointer (pointing to first element added; last)
//		only serves as a pointer to the array
// push_back: o(1) operation
// push_front: o(1) operation
// pop_back: o(1) operation
// pop_front: o(1) operation
// printAllElements o(n) operation
// insert_at: o(n) operation
 
using namespace std;

namespace LinkedLists {

    template<class Data>
    DoublyLinkedListWithHeadTailPointers<Data> :: Node :: Node(Data data): data(data) {}

    template<class Data> 
    DoublyLinkedListWithHeadTailPointers<Data> :: DoublyLinkedListWithHeadTailPointers() {}

    template<class Data> 
    bool DoublyLinkedListWithHeadTailPointers<Data> :: isEmpty() {
        return head == NULL;
    }

    template<class Data> 
    void DoublyLinkedListWithHeadTailPointers<Data> ::push_back(Data data) {
        if (head == NULL) {
            head = new Node(data);
            tail = head;
            length++;
            return;
        }
        Node* newNode = new Node(data);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        length++;

    }

    template<class Data> 
    void DoublyLinkedListWithHeadTailPointers<Data> ::push_front(Data data) {
        if (head == NULL) {
            head = new Node(data);
            tail = head;
            length++;
            return;

        }
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        length++;

    }

    template<class Data> 
    Data DoublyLinkedListWithHeadTailPointers<Data> :: pop_back() {
        assert(!isEmpty());
        if (tail->prev == NULL) {
            Data d = tail->data;
            delete tail;
            tail = NULL;
            length--;
            return d;
        }

        Node* previousNode = tail->prev;
        Data d = tail->data;
        delete tail;
        previousNode->next = NULL;
        tail = previousNode;
        length--;
        return d;
    }

    template<class Data> 
    Data DoublyLinkedListWithHeadTailPointers<Data> ::pop_front() {
        assert(!isEmpty());
        if (head->next == NULL) {
            Data d = head->data;
            delete head;
            head = NULL;
            length--;
            return d;
        }

        Node* nextNode = head->next;
        Data d = head->data;
        delete head;
        nextNode->prev = NULL;
        head = nextNode;
        length--;
        return d;
    
    }

    template<class Data> 
    void DoublyLinkedListWithHeadTailPointers<Data> :: printallElements() {
        if(head == NULL) {
            return;
        }

        Node* currentNode = head;
        while(currentNode != NULL) {
            cout << currentNode->data << endl;
            currentNode = currentNode->next;
        }

    }

    template<class Data>
    int DoublyLinkedListWithHeadTailPointers<Data> :: size() {
        return length;
    }

    template<class Data>
    void DoublyLinkedListWithHeadTailPointers<Data> :: insertAt(int index, Data data) {
        // 0 based indexing
        if (index >= length) {
            return;
        }
        if (index == 0) {
            push_front(data);
            return;

        }
        if (index == length - 1) {
            push_back(data);
            return;
        }
        
        Node* currentNode = head;
        Node* newNode = new Node(data);

        while(index > 0 ) {
            currentNode = currentNode->next;
            index--;
        }
        
        newNode->next = currentNode;
        newNode->prev = currentNode->prev;
        currentNode->prev->next = newNode;
        currentNode->prev = newNode;
        length++;

    }

    template<class Data>
    DoublyLinkedListWithHeadTailPointers<Data> :: ~DoublyLinkedListWithHeadTailPointers() {
        if (head == NULL) {
            return;
        }
        Node* currentNode = head;
        while(currentNode != NULL) {
            Node* deleteNode = currentNode;
            currentNode = currentNode->next;
            delete deleteNode;
        }
        head = NULL;
        tail = NULL;
    }

}