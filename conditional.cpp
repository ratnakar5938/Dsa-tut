#include <iostream>

using namespace std;
int main()
{
    char c;
    cin >> c;
    if (c >= 'A' && c <= 'Z')
    {
        cout << "This is upper case" << endl;
    }
    else if (c >= 'a' && c <= 'z')
    {
        cout << "THis is lower case" << endl;
    }
    else if (c >= '0' && c <= '9')
    {
        cout << "This is a numeric value" << endl;
    }
    else
    {
        cout << "Something else" << endl;
    }

    return 0;
}