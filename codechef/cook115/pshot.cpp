#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector <int> ans;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        n *= 2;
        int shot, left = n / 2, flag = 0;
        long long score = 0;
        cin.ignore(numeric_limits <streamsize> :: max(), '\n');
        string s;
        getline(cin, s);
        for (int j = 0; j < n; j++)
        {
            // cin >> shot;
            if (s[j] == '1')
                shot = 1;
            else
                shot = 0;
            if (j & 1)
            {   
                score -= shot;
                left--;
            }
            else
                score += shot;
            
            if (abs(score) > left && flag == 0)
                flag = j + 1;
        }
        if (flag == 0)
            ans.emplace_back(n);
        else
            ans.emplace_back(flag);
    }

    for (auto i : ans)
        cout << i << '\n';

    return 0;
}