#include "Queue.h"

// singly linked list implementation of a queue
// Classifications:
// front pointer is where removal occurs at (dequeue) o(1)
// back pointer is where insertion occurs at (enqueue) o(1)
// this way, we do not have to maintain doubly links 



using namespace std;

namespace StackQueues { 

    template<class Data> 
    Queue<Data> :: Queue() {}

    template<class Data> 
    void Queue<Data> :: enqueue(Data d) {
        if (front == NULL) {
            Node* newNode = new Node();
            newNode->data = d;
            front = newNode;
            back = newNode;
            return;
        }
        Node* newNode = new Node();
        newNode->data = d;
        back->next = newNode;
        back = newNode;
        if (front->next == NULL) {
            front->next = back;
        }

    }

    template<class Data> 
    Data Queue<Data> :: dequeue() {
        if (front == back) {
            Data d = front->data;
            delete front;
            front = NULL;
            back = NULL;
            return d;
        }

        Data d = front->data;
        Node* deleteNode = front;
        front = front->next;
        delete deleteNode;
        return d;

    }



}