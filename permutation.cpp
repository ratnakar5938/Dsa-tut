#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ans;

// --> permutation using recursive way
void permutation_recursive(vector<int> &a, int idx)
{
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        swap(a[i], a[idx]);
        permutation_recursive(a, idx + 1);
        swap(a[i], a[idx]);
    }
    return;
}

int main()
{
    cout << "Enter the size of the array u want to check the permutation of: ";
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    // permutation_recursive(a, 0);

    // --> permutaion using stl way
    sort(a.begin(), a.end());
    do
    {
        ans.push_back(a);
    } while (next_permutation(a.begin(), a.end()));

    for (auto v : ans)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// --> permutation with distinct value