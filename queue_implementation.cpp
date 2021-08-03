#include <iostream>

using namespace std;

#define n 20

class Queue
{
    int *arr;
    int front;
    int back;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int);
    void pop();
    int peek();
    bool empty();
};

void Queue::push(int x)
{
    if (back == n - 1)
    {
        cout << "Queue overflow" << endl;
        return;
    }
    back++;
    arr[back] = x;

    if (front == -1)
    {
        front++;
    }
}

void Queue::pop()
{
    if (front == -1 || front > back)
    {
        cout << "No elements in queue" << endl;
        return;
    }
    front++;
}

int Queue::peek()
{
    if (front == -1 || front > back)
    {
        cout << "No elements in queue" << endl;
        return -1;
    }
    return arr[front];
}

bool Queue::empty()
{
    if (front == -1 || front > back)
    {
        return true;
    }
    return false;
}

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();
    cout << endl;

    cout << q.empty() << endl;
    return 0;
}