#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low, high, mid;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] > element)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{

    int arr[] = {2, 5, 7, 8, 99, 105, 116, 150, 162};
    int size = sizeof(arr) / sizeof(int);
    int result, element;
    element = 162;

    // linear search --> works for both sorted and unsorted array
    // result = linearSearch(arr, size, element);
    // if (result != -1)
    // {
    //     cout << "Element is at index " << result << endl;
    // }
    // else
    // {
    //     cout << "Element not found" << endl;
    // }

    // binary serach works only for sorted arrays
    result = binarySearch(arr, size, element);
    if (result != -1)
    {
        cout << "Element " << element << " is at index " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}