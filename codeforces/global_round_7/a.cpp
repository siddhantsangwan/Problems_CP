#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        if (n == 1)
            cout << "-1\n";
        else if (n == 2)
        {
            cout << "23\n";
        }
        else
        {
            int ans = 23;
            cout << 23;
            while (n != 2)
            {
                cout << "3";
                n--;
            }
            cout << "\n";
        }
    }
    return 0;
}