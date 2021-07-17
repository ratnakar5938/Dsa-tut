#include <iostream>

using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sortedInsert(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int unSortedInsert(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    arr[size] = arr[index];
    arr[index] = element;
    return 1;
}

int main()
{
    const int capacity = 100;
    int arr[capacity] = {1, 4, 6, 8};
    int size = 4;
    display(arr, size);
    int element = 45;
    int index = 2;
    int success;

    // sorted insertion
    success = sortedInsert(arr, size, element, capacity, index);
    if (success == 1)
    {
        cout << "Insertion successful" << endl;
        size++;
        display(arr, size);
    }
    else
    {
        cout << "Insertion unsuccessful" << endl;
    }

    // unsorted insertion
    index = 1;
    element = 33;
    success = unSortedInsert(arr, size, element, capacity, index);
    if (success == 1)
    {
        cout << "Insertion successful" << endl;
        size++;
        display(arr, size);
    }
    else
    {
        cout << "Insertion unsuccessful" << endl;
    }
    return 0;
}