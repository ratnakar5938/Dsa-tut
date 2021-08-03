#include <iostream>
#include <stack>

using namespace std;

class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int);
    void pop();
    int peek();
    bool empty();
};

void Queue::push(int x)
{
    s1.push(x);
}

void Queue::pop()
{
    if (s1.empty() && s2.empty())
    {
        cout << "Queue Underflown" << endl;
        return;
    }
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    // int top = s2.top();
    s2.pop();
}

int Queue::peek()
{
    if (s1.empty() && s2.empty())
    {
        cout << "Queue Underflown" << endl;
        return -1;
    }
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int top = s2.top();
    return top;
}

bool Queue::empty()
{
    return (s1.empty() && s2.empty());
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
    q.pop();
    cout << endl;

    cout << q.empty() << endl;
    return 0;
}