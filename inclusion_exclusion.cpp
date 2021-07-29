#include <iostream>

using namespace std;

int divisible(int n, int a, int b)
{
    if (a == 0 || b == 0)
    {
        cout << "Divisibility error -> divided bt zero" << endl;
        return -1;
    }
    int c1 = 0, c2 = 0, c3 = 0;

    // --> my method

    // for (int i = 0; i < n; i++)
    // {
    //     if (i % a == 0)
    //     {
    //         c1++;
    //     }
    //     if (i % b == 0)
    //     {
    //         c2++;
    //     }
    //     if (i % a == 0 && i % b == 0)
    //     {
    //         c3++;
    //     }
    // }

    // --> instructors method

    c1 = n / a;
    c2 = n / b;
    c3 = n / (a * b);
    return c1 + c2 - c3;
}

int gcd(int a, int b)
{
    if (b > a)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

int main()
{
    // --> first question

    // cout << "Enter the number till which you want to check: ";
    // int n;
    // cin >> n;
    // cout << "Enter the first integer for division: ";
    // int a;
    // cin >> a;
    // cout << "Enter the second integer for division: ";
    // int b;
    // cin >> b;
    // cout << "Number of integers between 1 and " << n << " divisible by " << a << " or " << b << " is: " << divisible(n, a, b) << endl;

    // --> second question
    int a;
    int b;
    cout << "Enter the first integer: ";
    cin >> a;
    cout << "Enter the second integer: ";
    cin >> b;
    cout << "The gcd of " << a << " and " << b << " is: " << gcd(a, b) << endl;

    return 0;
}