#include <iostream>
#include <algorithm>

using namespace std;

int tilingWays(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return tilingWays(n - 1) + tilingWays(n - 2);
}

int friendsPairing(int n)
{
    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }
    return friendsPairing(n - 1) + (friendsPairing(n - 2) * (n - 1));
}

int knapsack(int value[], int wt[], int n, int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] > W)
    {
        return knapsack(value, wt, n - 1, W);
    }

    return max(knapsack(value, wt, n - 1, W - wt[n - 1]) + value[n - 1], knapsack(value, wt, n - 1, W));
}

int main()
{
    // --> question 1

    // cout << "Enter the integer: ";
    // int n;
    // cin >> n;
    // cout << "Number of ways is: " << tilingWays(n) << endl;

    // --> question 2

    // cout << "Enter the integer: ";
    // int n;
    // cin >> n;
    // cout << "Number of ways of pairing " << n << " friends is: " << friendsPairing(n) << endl;

    // --> question 2
    int wt[] = {10, 20, 30};
    int value[] = {100, 50, 150};
    int W = 50;
    cout << knapsack(value, wt, 3, W) << endl;

    return 0;
}