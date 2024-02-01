#ifndef DOUBLE_LINKED_LIST

#define DOUBLE_LINKED_LIST

// Implementation of a Double Linked List with Head Pointer and Tail Pointer
// Classifications:
// Doubly Linked
//  Head Pointer and Tail Pointer (pointing to first element added; last)
//		only serves as a pointer to the array
// push_back: o(1) operation
// push_front: o(1) operation
// pop_back: o(1) operation
// pop_front: o(1) operation
// printAllElements / printallElementsRecrusiver: o(n) operation
// reverse: o(n) operation

using namespace std;

namespace LinkedLists {
    template<class Data>
    class DoublyLinkedListWithHeadTailPointers {
        private:
        struct Node {
            Node* next = NULL;
            Node* prev = NULL;
            Data data;
            Node(Data data);
        };

        Node* head = NULL;
        Node* tail = NULL;
        int length = 0;
        public: 
        DoublyLinkedListWithHeadTailPointers();

        ~DoublyLinkedListWithHeadTailPointers();

        void push_back(Data data);

        void push_front(Data data);

        Data pop_back();

        Data pop_front();

        bool isEmpty();

        void printallElements();

        int size();

        void insertAt(int index, Data data); // 0 based indexing



    };
}

#endif