#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 0, sum = 0;
    while (i <= n)
    {
        sum += i;
        i += 2;
    }
    cout << "Sum of all even numbers till " << n << " is : " << sum << endl;
    return 0;
}