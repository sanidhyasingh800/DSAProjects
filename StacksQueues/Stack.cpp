#include "Stack.h"

// dynamic resizing array implementation of Stack
// Classifications:
// push: o(1) amortized time complexity (o(n)/n)
// pop: o(1) time complexity since resizing will not shrink

using namespace std;

namespace StackQueues {

    template<class Data>
    Stack<Data> :: Stack() {
        array = new Data[1];
        size = 0;
        capacity = 1;
    }

    template<class Data>
    void Stack<Data> :: push(Data d) {
        if (size == capacity) {
            Data* newArray = new Data[capacity * 2];
            for (int i = 0; i<size; i++) {
                newArray[i] = array[i];

            }
            delete[] array;
            array = newArray;
            capacity = capacity * 2;
        }
        array[size++] = d;
    }

    template<class Data>
    Data Stack<Data> :: pop() {

        Data d = array[size-1];
        size--;
        return d;
    }

    template<class Data>
    bool Stack<Data> :: isEmpty() {
        return size != 0;
    }

    template<class Data>
    Stack<Data> :: ~Stack() {
        delete[] array;
    }
}