#include <iostream>

using namespace std;
int main()
{
    const int n = 6;
    int num[n];

    cout << "enter the element: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for (int i = 1; i < n; i++)
    {
        int current = num[i];
        int j = i - 1;
        while (num[j] > current && j >= 0)
        {
            num[j + 1] = num[j];
            j--;
        }
        num[j + 1] = current;
    }

    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }
    return 0;
}