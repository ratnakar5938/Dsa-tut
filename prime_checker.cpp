#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 2;
    bool isPrime = true;
    while (i < n)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
        i++;
    }
    if (isPrime)
    {
        cout << n << " is a prime number" << endl;
    }
    else
    {
        cout << n << " is not a prime number" << endl;
    }

    return 0;
}