// printing primes in a more efficient way --> Sieve of Erathosthenes
#include <iostream>

using namespace std;

void primeSieve(int n)
{
    int prime[100] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    cout << "Primes are: ";
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << " ";
        }
    }
}

void primeFactor(int n)
{
    int spf[100] = {0};
    for (int i = 2; i <= n; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    cout << "Prime factors of " << n << " are: ";
    while (n != 1)
    {
        cout << spf[n] << " ";
        n = n / spf[n];
    }
}

int main()
{
    cout << "Enter the number till which you need to print the prime numbers between 1 and 100: ";
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "Prime and prime factors cannot be determined for any integer under 2" << endl;
    }
    else
    {
        primeSieve(n);
        cout << endl;
        primeFactor(n);
    }

    return 0;
}