#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cin.ignore(numeric_limits <streamsize> :: max(), '\n');
        string s;
        getline(cin, s);

        char last = 0;
        char cur = 0;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'U' || s[i] == 'D')
                cur = 'a';
            else
                cur = 'b';
            if (cur == last)
                continue;
            else
            {
                if (s[i] == 'U' || s[i] == 'D')
                    last = 'a';
                else
                    last = 'b';
                if (s[i] == 'U')
                    y += 1;
                else if(s[i] == 'D')
                    y--;
                else if(s[i] == 'L')
                    x--;
                else
                    x++;
            }
        }
        cout << x << " " << y << '\n';
    }
    return 0;
}