#include <iostream>

using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int temp1 = mid - l + 1;
    int temp2 = r - mid;

    int a[temp1];
    int b[temp2];
    for (int i = 0; i < temp1; i++)
    {
        a[i] = arr[l + i];
    }

    for (int i = 0; i < temp2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < temp1 && j < temp2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < temp1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < temp2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main()
{
    int arr[] = {5, 6, 2, 1, 8, 21, 7};
    mergeSort(arr, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}