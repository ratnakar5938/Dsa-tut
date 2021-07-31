#include <iostream>

using namespace std;

void countSort(int arr[], int n)
{
    int k = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > k)
        {
            k = arr[i];
        }
    }

    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 0; i <= k; i++)
    {
        if (i > 0)
        {
            count[i] += count[i - 1];
        }
    }

    int output[n];

    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int arr[] = {1, 2, 4, 1, 3};
    countSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}