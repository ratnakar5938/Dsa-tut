#include <iostream>
#include <string>

using namespace std;

void permuteStr(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string res = s.substr(0, i) + s.substr(i + 1);
        permuteStr(res, ans + ch);
    }
}

int getPath(int s, int e)
{
    if (s == e)
    {
        return 1;
    }
    if (s > e)
    {
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += getPath(s + i, e);
    }
    return count;
}

int getPathMaze(int n, int i, int j)
{
    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }
    if (i >= n || j >= n)
    {
        return 0;
    }
    return getPathMaze(n, i + 1, j) + getPathMaze(n, i, j + 1);
}

int main()
{
    // --> question 1

    // cout << "Enter the string: ";
    // string s;
    // cin >> s;
    // permuteStr(s, "");

    // --> question 2

    // cout << "Enter the starting integer: ";
    // int a, b;
    // cin >> a;
    // cout << "Enter the ending integer: ";
    // cin >> b;
    // cout << getPath(a, b) << endl;

    // --> question 2
    cout << "Enter the dimension: ";
    int n;
    cin >> n;
    cout << getPathMaze(n, 0, 0);
    return 0;
}