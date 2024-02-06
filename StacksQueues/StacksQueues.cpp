#include <iostream>
#include "Stack.h"
#include  "Stack.cpp"
#include "Queue.h"
#include  "Queue.cpp"

using namespace std;
using namespace StackQueues;

int main() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    int a = stack.pop();
    cout << a << endl;
    a = stack.pop();
    cout << a << endl;

    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    int b = queue.dequeue();
    cout << b<< endl;
    b = queue.dequeue();
    cout << b << endl;
       b = queue.dequeue();
    cout << b << endl;
       b = queue.dequeue();
    cout << b << endl;


}