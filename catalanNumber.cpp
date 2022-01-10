#include <iostream>

using namespace std;

int catlanNumber(int key)
{
    if (key <= 1)
    {
        return 1;
    }

    int result = 0;
    for (int i = 0; i < key; i++)
    {
        result += catlanNumber(i) * catlanNumber(key - i - 1);
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter i to get the ith term in catlan: ";
    cin >> n;
    cout << "Catlan term for " << n << " is " << catlanNumber(n) << endl;
    return 0;
}

// Applications of catlan number ->
//      1. Posiible BSTs
//      2. Parenthesis / bracket combination
//      3. Possible forests
//      4. Ways of triangulations
//      5. Possible paths in a matrix
//      6. Dividing a circle using N chords
//      7. Dyck words of given length and much more