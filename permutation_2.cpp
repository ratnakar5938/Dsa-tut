#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void helper(vector<int> a, vector<vector<int>> &ans, int idx)
{
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        if (i != idx && a[i] == a[idx])
        {
            continue;
        }
        swap(a[i], a[idx]);
        helper(a, ans, idx + 1);
    }
}

vector<vector<int>> permute(vector<int> num)
{
    sort(num.begin(), num.end());
    vector<vector<int>> ans;
    helper(num, ans, 0);
    return ans;
}

int main()
{
    cout << "Enter the size of the array u want to check the permutation of: ";
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    cout << endl;
    vector<vector<int>> ans = permute(a);
    for (auto v : ans)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// --> permuatations without distinct value