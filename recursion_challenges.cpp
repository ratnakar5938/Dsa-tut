#include <iostream>

using namespace std;

bool sorted(int arr[], int size)
{
    if (size == 1)
    {
        return true;
    }

    bool restArray = sorted(arr + 1, size - 1);
    return (arr[0] < arr[1] && restArray);
}

void decrement(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    decrement(n - 1);
}

void increment(int n)
{
    if (n == 0)
    {
        return;
    }
    increment(n - 1);
    cout << n << endl;
}

int firstOccurence(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }

    if (arr[i] == key)
    {
        return i;
    }
    return firstOccurence(arr, n, i + 1, key);
}

// --> my method

// int lastOccurence(int arr[], int n, int i, int key)
// {
//     if (i == -1)
//     {
//         return -1;
//     }
//     if (arr[i] == key)
//     {
//         return i;
//     }
//     return lastOccurence(arr, n, i - 1, key);
// }

// --> instructor's method

int lastOccurence(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }

    int restArr = lastOccurence(arr, n, i + 1, key);

    if (restArr != -1)
    {
        return restArr;
    }

    if (arr[i] == key)
    {
        return i;
    }

    return -1;
}

int main()
{
    // --> question 1

    // cout << "Enter size of array: ";
    // int n;
    // cin >> n;
    // int *arr = new int[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // cout << "Is the array sorted: " << sorted(arr, n) << endl;

    // --> question 2

    // cout << "Enter the number till which u want to print: ";
    // int n;
    // cin >> n;
    // decrement(n);
    // cout << endl;
    // increment(n);

    // --> question 3
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element u want to find: ";
    int a;
    cin >> a;
    cout << "First occurence of " << a << " is at: " << firstOccurence(arr, n, 0, a) << endl;
    // cout << "Last occurence of " << a << " is at: " << lastOccurence(arr, n, n, a) << endl;
    cout << "Last occurence of " << a << " is at: " << lastOccurence(arr, n, 0, a) << endl;

    return 0;
}