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

void sort_delete_element(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

void unsort_delete_element(int arr[], int size, int index)
{
    arr[index] = arr[size - 1];
}

int main()
{
    const int capacity = 100;
    int arr[capacity] = {5, 7, 8, 22, 74};
    int index = 2, size = 5;
    display(arr, size);

    sort_delete_element(arr, size, index);
    size--;
    display(arr, size);

    index = 1;
    unsort_delete_element(arr, size, index);
    size--;
    display(arr, size);
    return 0;
}