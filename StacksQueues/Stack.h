#ifndef STACK
#define STACK

// dynamic resizing array implementation of Stack
// Classifications:
// push: o(1) amortized time complexity (o(n)/n)
// pop: o(1) time complexity since resizing will not shrink

using namespace std;

namespace StackQueues {
    template<class Data>
    class Stack {
    private:
        Data* array;
        int size;
        int capacity;
    public:
        Stack();

        void push(Data d);
        Data pop();

        bool isEmpty();

        ~Stack();
        
    };
}


#endif