#include <bits/stdc++.h>
using namespace std;

int countElements(vector<int>& arr) {
    unordered_map<int, int> m (arr.size());
    
    int count = 0;
    for (auto i : arr)
    {
        m[i] += 1;
    }
    for (auto i : m)
    {
        if (m.find(i.first + 1) != m.end())
            count += i.second;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    cin >> v[i];

    cout << countElements(v);
    return 0;
}