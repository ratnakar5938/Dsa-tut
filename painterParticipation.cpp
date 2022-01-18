#include <iostream>
#include <algorithm>

using namespace std;

int findFeasible(int arr[], int n, int limit)
{
    int s = 0, painters = 1;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        if (s > limit)
        {
            painters++;
            s = arr[i];
        }
    }

    return painters;
}

int paintersParticipation(int boards[], int n, int m)
{
    int totalLength = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        k = max(k, boards[i]);
        totalLength += boards[i];
    }

    int low = k, high = totalLength;
    int mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        int painter = findFeasible(boards, n, mid);
        if (painter <= m)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    int boards[] = {10, 20, 30, 40};
    int n = 4;
    int m = 2;

    cout << "Minimum time to paint boards : " << paintersParticipation(boards, n, m) << endl;

    return 0;
}