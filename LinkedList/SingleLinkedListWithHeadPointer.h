#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST
using namespace std;

// Implementation of a Single Linked List with Head Pointer
// Classifications:
// Singly Linked
// Single Head Pointer (pointing to first element added)
//		only serves as a pointer to the array
// push: o(n) operation
// remove 


namespace LinkedLists {
template<typename Data>
class SingleLinkedListWithHeadPointer {
private:
	struct Node {
		Node* next = NULL;
		Data data;
		Node(Data data);
	};

    Node* head = NULL;

	void printAllElementsRecursive(Node* node);
public:

	SingleLinkedListWithHeadPointer();

	bool isEmpty();

	void push_back(Data data);

	void push_front(Data data);

	Data pop_back();

	Data pop_front();

	void printAllElements();

	void printAllElementsRecursive();

	void reverseList();

};
}

#endif