#include <iostream>

using namespace std;

class MyArray
{
    int total_size, used_size;
    int *ptr;

public:
    MyArray(int, int); // constructor used instead of createArray method
    // void createArray(int, int);
    void showArray();
    void setVal();
};

MyArray::MyArray(int t_size, int u_size)
{
    total_size = t_size;
    used_size = u_size;
    // ptr = (int *)malloc(t_size * sizeof(int));
    ptr = new int[t_size];
}

// void MyArray::createArray(int t_size, int u_size)
// {
//     total_size = t_size;
//     used_size = u_size;
//     // ptr = (int *)malloc(t_size * sizeof(int));
//     ptr = new int[t_size];
// }

void MyArray::showArray()
{
    for (int i = 0; i < used_size; i++)
    {
        cout << ptr[i] << endl;
    }
}

void MyArray::setVal()
{
    for (int i = 0; i < used_size; i++)
    {
        cout << "Enter the " << i << " elements: ";
        cin >> ptr[i];
    }
}

int main()
{
    MyArray marks(20, 10);
    // marks.createArray(20, 10);
    cout << "Setting value in the array" << endl;
    marks.setVal();
    cout << "Showing value in the array" << endl;
    marks.showArray();
    return 0;
}