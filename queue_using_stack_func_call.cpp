#include <iostream>
#include <stack>

using namespace std;
class Queue
{
    stack<int> s1;

public:
    void push(int);
    int pop();
    bool empty();
};

void Queue::push(int x)
{
    s1.push(x);
}

int Queue::pop()
{
    if (s1.empty())
    {
        cout << "Queue Underflown" << endl;
        return -1;
    }
    int x = s1.top();
    s1.pop();
    if (s1.empty())
    {
        return x;
    }
    int item = pop();
    s1.push(x);
    return item;
}

bool Queue::empty()
{
    return s1.empty();
}

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.pop() << endl;

    cout << q.pop() << endl;

    cout << q.pop() << endl;

    cout << q.pop() << endl;
    q.pop();
    cout << endl;

    cout << q.empty() << endl;
    return 0;
}