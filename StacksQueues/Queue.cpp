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
        Node* newNode = new Node();
        newNode->data = d;
        if (front == NULL) {
            front = newNode;
            back = newNode;
            return;
        }
        back->next = newNode;
        back = newNode;

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

    template<class Data>
    Queue<Data> :: ~Queue() {
        while(front != NULL) {
            dequeue();
        }
    }



}