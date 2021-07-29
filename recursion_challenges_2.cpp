#include <iostream>
#include <string>

using namespace std;

// --> my method
void reverseStr(string n, int i)
{
    if (i == -1)
    {
        return;
    }
    cout << n[i];
    reverseStr(n, i - 1);
}

void reverseStr2(string n)
{
    if (n.size() == 0)
    {
        return;
    }
    string rest = n.substr(1);
    reverseStr2(rest);
    cout << n[0];
}

void replacePi(string n)
{
    if (n.length() == 0)
    {
        return;
    }
    string rest;
    if (n[0] == 'p' && n[1] == 'i')
    {
        cout << "3.14";
        rest = n.substr(2);
        replacePi(rest);
    }
    else
    {
        rest = n.substr(1);
        cout << n[0];
        replacePi(rest);
    }
}

void towerOfHanoi(int n, char src, char dest, char helper)
{
    if (n == 0)
    {
        return;
    }

    towerOfHanoi(n - 1, src, helper, dest);
    cout << "Move from " << src << " to " << dest << endl;
    towerOfHanoi(n - 1, helper, dest, src);
}

string removeDup(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string res = removeDup(s.substr(1));

    if (ch == res[0])
    {
        return res;
    }
    else
    {
        return (ch + res);
    }
}

string moveX(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string res = moveX(s.substr(1));
    if (ch == 'x')
    {
        return (res + ch);
    }
    return (ch + res);
}

void subStrGen(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string res = s.substr(1);
    subStrGen(res, ans);
    subStrGen(res, ans + ch);
}

void subStrGen_next(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string res = s.substr(1);
    int code = ch;
    subStrGen_next(res, ans);
    subStrGen_next(res, ans + ch);
    subStrGen_next(res, ans + to_string(code));
}

string KeyPadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keyPad(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string code = KeyPadArr[ch - '0'];
    string res = s.substr(1);
    for (int i = 0; i < code.length(); i++)
    {
        keyPad(res, ans + code[i]);
    }
}

int main()
{
    // --> question 1

    // cout << "Enter the string: ";
    // string n;
    // cin >> n;
    // // reverseStr(n, n.size() - 1);
    // reverseStr2(n);

    // --> question 2

    // cout << "Enter the string: ";
    // string n;
    // cin >> n;
    // replacePi(n);

    // --> question 3

    // towerOfHanoi(3, 'A', 'C', 'B');

    // --> question 4

    // cout << "enter the string: ";
    // string s;
    // cin >> s;
    // cout << removeDup(s) << endl;

    // --> question 5

    // cout << "enter the string: ";
    // string s;
    // cin >> s;
    // cout << moveX(s) << endl;

    // --> question 6

    // cout << "enter the string: ";
    // string s;
    // cin >> s;
    // subStrGen(s, "");
    // subStrGen_next(s, "");

    // --> question 7

    cout << "Enter the string: ";
    string s;
    cin >> s;
    keyPad(s, "");

    return 0;
}