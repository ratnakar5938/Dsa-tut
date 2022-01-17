#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

bool isPossible(int mid, int arr[], int n, int k)
{
    int studentsReq = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        if (sum + arr[i] > mid)
        {
            studentsReq++;
            sum = arr[i];
            if (studentsReq > k)
            {
                return false;
            }
        }
        else
        {
            sum += arr[i];
        }
    }

    return true;
}

int allocateMinimumPages(int arr[], int n, int k)
{
    sort(arr, arr + n);
    if (n < k)
    {
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int start = 0, end = sum, ans = INT_MAX;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (isPossible(mid, arr, n, k))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;

    cout << "The minimum number of pages : " << allocateMinimumPages(arr, n, m) << endl;

    return 0;
}