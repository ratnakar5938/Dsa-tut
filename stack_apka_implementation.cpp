#include <iostream>

using namespace std;

#define n 100

class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int);
    void pop();
    int topElemnt();
    bool empty();
    void display();
};

void Stack::push(int x)
{
    if (top == n - 1)
    {
        cout << "Stack overflow" << endl;
        return;
    }
    top++;
    arr[top] = x;
}

void Stack::pop()
{
    if (top == -1)
    {
        cout << "Stack underflow" << endl;
        return;
    }
    top--;
}

int Stack::topElemnt()
{
    if (top == -1)
    {
        cout << "Stack has no data stored" << endl;
        return -1;
    }
    return arr[top];
}

bool Stack::empty()
{
    return top == -1;
}

void Stack::display()
{
    if (top == -1)
    {
        cout << "Stack has no data" << endl;
        return;
    }
    int pos = top;
    while (pos >= 0)
    {
        cout << arr[pos] << "->";
        pos--;
    }
    cout << "END" << endl;
}

int main()
{
    Stack st;
    st.push(45);
    st.push(44);
    st.push(35);
    st.push(75);
    st.push(90);
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    cout << st.topElemnt() << endl;
    cout << "Is empty: " << st.empty() << endl;
    st.display();
    return 0;
}