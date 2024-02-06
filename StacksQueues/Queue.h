#ifndef QUEUE
#define QUEUE


// singly linked list implementation of a queue
// Classifications:
// front pointer is where removal occurs at (dequeue) o(1)
// back pointer is where insertion occurs at (enqueue) o(1)
// this way, we do not have to maintain doubly links 


using namespace std;

namespace StackQueues{
template <class Data>
class Queue {
public:
    Queue();
    // bool is_empty() const;
    void enqueue(Data e);
    Data dequeue();
private:
    struct Node {
        Data data;
        Node* next;
    };
    Node* front = NULL;
    Node* back = NULL;
};
}

#endif