#include <iostream>
#include <algorithm>

using namespace std;

// recursive method
void dnfSort_rec(int arr[], int l, int mid, int h)
{
    if (mid == h)
    {
        return;
    }

    if (arr[mid] == 0)
    {
        swap(arr[l], arr[mid]);
        l++;
        mid++;
        dnfSort_rec(arr, l, mid, h);
    }
    else if (arr[mid] == 1)
    {
        mid++;
        dnfSort_rec(arr, l, mid, h);
    }
    else if (arr[mid] == 2)
    {
        swap(arr[mid], arr[h]);
        h--;
        dnfSort_rec(arr, l, mid, h);
    }
}

// iterative method
void dnfSort_iter(int arr[], int n)
{
    int mid = 0, low = 0, high = n - 1;
    while (mid != high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = {1, 1, 0, 0, 0, 1, 2, 2, 1, 2};
    // dnfSort_rec(arr, 0, 0, 9);
    dnfSort_iter(arr, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}