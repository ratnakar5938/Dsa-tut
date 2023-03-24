#include <iostream>

using namespace std;

void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (i * 3) + (j + 1) << " ";
        }
        cout << endl;
    }
}

void pattern3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

void pattern4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << (i + 1) + j << " ";
        }
        cout << endl;
    }
}
/*
1
2 3
4 5 6
7 8 9 10
*/
void pattern5(int n)
{
    int value = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << ++value << " ";
        }
        cout << endl;
    }
}

void pattern6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << (i + 1) - j << " ";
        }
        cout << endl;
    }
}

void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << char(65 + i) << " ";
        }
        cout << endl;
    }
}

void pattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << char(65 + i) << " ";
        }
        cout << endl;
    }
}

void pattern9(int n)
{
    int value = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << char(65 + (value++)) << " ";
        }
        cout << endl;
    }
}

void pattern10(int n)
{
    // int value = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << char(65 + (n - 1) - i + j) << " ";
        }
        cout << endl;
    }
}

void pattern11(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (n - j <= i + 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void pattern12(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (n - j > i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void pattern13(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void pattern14(int n)
{
    int row = 1;
    while (row <= n)
    {
        int space = n - row;
        while (space)
        {
            cout << " ";
            space--;
        }
        int j = 1;
        while (j <= row)
        {
            cout << j;
            j++;
        }
        int start = row - 1;
        while (start)
        {
            cout << start;
            start--;
        }
        cout << endl;
        row++;
    }
}

/*
12345
1234
123
12
1
*
**
***
****
*/
void pattern15(int n)
{
    int row = 1;
    while (row <= n)
    {
        int j = 1;
        while (j <= n - row + 1)
        {
            cout << j;
            j++;
        }
        int start = row - 1;
        while (start)
        {
            cout << "*";
            start--;
        }
        int start2 = row - 1;
        while (start2)
        {
            cout << "*";
            start2--;
        }
        int k = n - row + 1;
        while (k)
        {
            cout << k;
            k--;
        }
        cout << endl;
        row++;
    }
}

int main()
{
    int n;
    cin >> n;
    pattern15(n);

    return 0;
}