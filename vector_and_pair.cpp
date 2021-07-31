#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myCompare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

int main()
{
    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);

    // --> method 1

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << endl;
    // }

    // --> method 2

    // vector<int>::iterator i;
    // for (i = v.begin(); i != v.end(); i++)
    // {
    //     cout << *i << endl;
    // }

    // --> method 3

    // for (auto element : v)
    // {
    //     cout << element << endl;
    // }

    // cout << endl;
    // v.pop_back();

    // vector<int> v2(3, 50);

    // swap(v, v2); // --> swapping the elements of the vectors

    // for (auto element : v)
    // {
    //     cout << element << endl;
    // }

    // cout << endl;

    // for (auto element : v2)
    // {
    //     cout << element << endl;
    // }

    // pair<int, char> p;
    // p.first = 3;
    // p.second = 'r';

    int arr[] = {10, 16, 7, 14, 5, 3, 2, 9};
    vector<pair<int, int>> v;
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        // pair<int, int> p;
        // p.first = arr[i];
        // p.second = i;
        // v.push_back(p);

        v.push_back(make_pair(arr[i], i));
    }

    sort(v.begin(), v.end(), myCompare);
    for (int i = 0; i < v.size(); i++)
    {
        arr[v[i].second] = i;
    }

    cout << "reduced form of array: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}