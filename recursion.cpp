#include <iostream>

using namespace std;

int addN(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + addN(n - 1);
}

long int nRaiseP(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }

    int prevState = nRaiseP(n, p - 1);
    return n * prevState;
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    // --> question 1

    // cout << "Enter the integer: ";
    // int n;
    // cin >> n;
    // cout << "Sum of all integer till " << n << " is: " << addN(n) << endl;

    // --> question 2

    // int a, b;
    // cout << "Enter the base: ";
    // cin >> a;
    // cout << "Enter the power: ";
    // cin >> b;
    // cout << a << " raised to the power " << b << " is: " << nRaiseP(a, b) << endl;

    // -->question 3

    // int n;
    // cout << "Enter the integer: ";
    // cin >> n;
    // cout << "Factorial of " << n << " is: " << factorial(n) << endl;

    // --> question 4

    int n;
    cout << "Enter the element you want to get in fibonacci series: ";
    cin >> n;
    cout << "Element at " << n << " position of fibonacci is: " << fibonacci(n) << endl;
    return 0;
}