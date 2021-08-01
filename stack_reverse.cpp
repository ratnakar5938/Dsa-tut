#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertAtBottom(st, ele);

    st.push(topElement);
}

void reverse(stack<int> &st)
{

    if (st.empty())
    {
        return;
    }

    int element = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, element);
}

int main()
{
    stack<int> st;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        st.push(arr[i]);
    }

    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;

    reverse(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}