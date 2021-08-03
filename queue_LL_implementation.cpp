#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    Node *front;
    Node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }
    void push(int);
    void pop();
    int peek();
    bool empty();
};

void Queue::push(int x)
{
    Node *n = new Node(x);
    if (front == NULL)
    {
        back = n;
        front = n;
        return;
    }

    back->next = n;
    back = n;
}

void Queue::pop()
{
    if (front == NULL)
    {
        cout << "Queue underflown" << endl;
        return;
    }
    Node *toDelete = front;
    front = front->next;
    delete toDelete;
}

int Queue::peek()
{
    if (front == NULL)
    {
        cout << "No element in Queue" << endl;
        return -1;
    }
    return front->data;
}

bool Queue::empty()
{
    return front == NULL;
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