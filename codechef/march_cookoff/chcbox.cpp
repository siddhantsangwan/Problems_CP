#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, x;
        cin >> n;
        int left_max = INT_MIN, right_max = INT_MIN;
        int left = -1, right = -1;
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            if (x > left_max)
            {
                left_max = x;
                left = j;
            }
            else if (x == left_max)
            {
                right = j;
            }
        }
        if (right < left)
            cout << n/2 << '\n';
        else if (right - left >= n/2)
            cout << 0 << '\n';
        else
        {
            cout << n/2 - (right - left) << '\n';
        }
    }
    return 0;
}