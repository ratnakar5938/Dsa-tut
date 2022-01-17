#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
    // ordered set - <set>
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(5);

    // forward printing
    for (auto i : s)
        cout << i << " ";

    cout << endl;

    // reverse printing
    for (auto i = s.rbegin(); i != s.rend(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;

    // creating a set of decsending order
    set<int, greater<int>> s2;
    s2.insert(1);
    s2.insert(3);
    s2.insert(2);
    s2.insert(5);
    s2.insert(4);

    for (auto i : s2)
        cout << i << " ";

    cout << endl;

    // lower and upper bounds
    // cout << *s.lower_bound(2) << endl;
    // cout << *s.lower_bound(3) << endl;
    // cout << *s.upper_bound(3) << endl;
    // cout << (s.upper_bound(5) == s.end()) << endl;

    // erase
    s2.erase(2);
    s2.erase(s2.begin());
    for (auto i : s2)
        cout << i << " ";
    cout << endl;

    // multiset - <set>
    multiset<int> s3;
    s3.insert(1);
    s3.insert(3);
    s3.insert(3);
    s3.insert(3);
    s3.insert(5);

    for (auto i : s3)
        cout << i << " ";
    cout << endl;

    // s3.erase(3); // erase all occurences
    s3.erase(s3.find(3)); // only erases first occurence
    for (auto i : s3)
        cout << i << " ";
    cout << endl;

    // unordered set - <unordered_set>
    unordered_set<int> s4;
    s4.insert(3);
    s4.insert(3);
    s4.insert(2);
    s4.insert(1);
    s4.insert(5);

    for (auto i : s4)
        cout << i << " ";
    cout << endl;

    s4.erase(2);
    s4.erase(s4.begin());

    for (auto i : s4)
        cout << i << " ";
    cout << endl;

    // Insertion -> O(1) in avg case, O(N) in worst case
    // Deletion -> O(1) in avg case, O(N) in worst case
    // Upper and lower bound not possible

    return 0;
}