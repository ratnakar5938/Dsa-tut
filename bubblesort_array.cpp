#include <iostream>

using namespace std;
int main()
{
    const int n = 6;
    int num[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << " element: ";
        cin >> num[i];
    }

    int counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (num[i] > num[i + 1])
            {
                int temp = num[i];
                num[i] = num[i + 1];
                num[i + 1] = temp;
            }
        }
        counter++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }
    return 0;
}