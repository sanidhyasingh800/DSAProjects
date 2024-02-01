#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST
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

	~SingleLinkedListWithHeadPointer();

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