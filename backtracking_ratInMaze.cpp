#include <iostream>

using namespace std;

bool isValid(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ratInMaze(int **arr, int x, int y, int n, int **solArr)
{
    if (x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;
        return true;
    }

    if (isValid(arr, x, y, n))
    {
        solArr[x][y] = 1;
        if (ratInMaze(arr, x + 1, y, n, solArr))
        {
            return true;
        }
        if (ratInMaze(arr, x, y + 1, n, solArr))
        {
            return true;
        }
        solArr[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    cout << "Enter the dimension of square matrix: ";
    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << "Enter the element at " << j << " of line " << i << " : ";
            cin >> arr[i][j];
        }
    }

    int **solArr = new int *[n];
    // for (int i = 0; i < n; i++)
    // {
    //     solArr[i] = new int[n];
    // }
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }

    if (ratInMaze(arr, 0, 0, n, solArr))
    {
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

/*

1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1

*/