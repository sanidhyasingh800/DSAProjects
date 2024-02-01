
#include <iostream>
#include <cassert>
#include "SingleLinkedListWithHeadPointer.h"
using namespace std;

// Implementation of a Single Linked List with Head Pointer
// Classifications:
// Singly Linked
// Single Head Pointer (pointing to first element added)
//		only serves as a pointer to the array
// push_back: o(n) operation
// push_front: o(1) operation
// pop_back: o(n) operation
// pop_front: o(1) operation
// printAllElements / printallElementsRecrusiver: o(n) operation
// reverse: o(n) operation


namespace LinkedLists {
template<class Data>
SingleLinkedListWithHeadPointer<Data> :: Node :: Node(Data data): data(data) {}

template<class Data> 
SingleLinkedListWithHeadPointer<Data> :: SingleLinkedListWithHeadPointer() {}

template<class Data>
bool SingleLinkedListWithHeadPointer<Data> :: isEmpty() {
	return head == NULL;
}

template<class Data> 
void SingleLinkedListWithHeadPointer<Data> :: push_back(Data data) {
	if (head == NULL) {
			head = new Node(data);
			return;
		}
		Node* currentNode = head;
		while (currentNode->next != NULL) {
			currentNode = currentNode->next;
		}
		Node* newNode = new Node(data);
		currentNode->next = newNode;
}

template<class Data>
void SingleLinkedListWithHeadPointer<Data> :: push_front(Data data) {
	Node* newNode = new Node(data);
	newNode->next = head;
	head = newNode;
}

template<class Data>
Data SingleLinkedListWithHeadPointer<Data> :: pop_back() {
	assert(!isEmpty());

	if (head->next == NULL){
		Data d = head->data;
		delete head;
		head = NULL;
		return d;
	}
	Node* currentNode = head;
	Node* previousNode = currentNode;
	while (currentNode->next != NULL){
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	Data d = currentNode->data;
	delete currentNode;
	previousNode->next = NULL;
	return d;
}

template<class Data>
Data SingleLinkedListWithHeadPointer<Data> :: pop_front() {
	assert(!isEmpty());
	Data d = head->data;
	Node* deleteNode = head;
	head = head->next;
	delete deleteNode;
	deleteNode = NULL;
	return d;
}


template<class Data> 
void SingleLinkedListWithHeadPointer<Data> :: printAllElements() {
	Node* currentNode = head;
		while (currentNode != NULL) {
			cout << currentNode->data << endl;
			currentNode = currentNode->next;
		}
}

template<class Data> 
void SingleLinkedListWithHeadPointer<Data> :: printAllElementsRecursive() {
	printAllElementsRecursive(head);
}

template<class Data> 
void SingleLinkedListWithHeadPointer<Data> :: printAllElementsRecursive(Node* node) {
	if (node == NULL) {
		return;
	}
	if(node->next != NULL) {
		printAllElementsRecursive(node->next);
	}
	// base case 
	cout << node->data << endl;
}


template<class Data> 
void SingleLinkedListWithHeadPointer<Data> :: reverseList() {
	if (head == NULL || head->next == NULL) {
		return;
	}
	Node* currentNode = head;
	Node* previousNode = NULL;
	Node* nextNode = currentNode->next;
	while(currentNode != NULL) {
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
		if (nextNode != NULL){
			nextNode = nextNode->next;
		}
	}

	head = previousNode;

}

    template<class Data>
    SingleLinkedListWithHeadPointer<Data> :: ~SingleLinkedListWithHeadPointer() {
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
    }

}
