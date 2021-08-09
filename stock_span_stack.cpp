#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> stockspan(vector<int> prices)
{
    vector<int> ans;
    stack<pair<int, int>> st;
    for (auto price : prices)
    {
        int days = 1;
        while (!st.empty() && st.top().first <= price)
        {
            days += st.top().second;
            st.pop();
        }
        st.push({price, days});
        ans.push_back(days);
    }
    return ans;
}

int main()
{
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = stockspan(prices);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}