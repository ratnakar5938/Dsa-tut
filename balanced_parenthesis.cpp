#include <iostream>
#include <stack>

using namespace std;

bool isBalancedParenthesis(string s)
{
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty())
            {
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty())
            {
                if (st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty())
            {
                if (st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            else
            {
                ans = false;
                break;
            }
        }
    }

    if (!st.empty())
    {
        ans = false;
    }

    return ans;
}

int main()
{
    if (isBalancedParenthesis("(4+3+5*[76+98)]-{78+98}"))
    {
        cout << "Expression has balanced parenthesis" << endl;
    }
    else
    {
        cout << "Expression has unbalanced parenthesis" << endl;
    }

    return 0;
}