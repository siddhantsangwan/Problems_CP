#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, q;
        cin >> n >> q;
        vector <int> range(n + 1, 0);
        vector <int> input(n, 0);
        for (int j = 0; j < n; j++)
        {
            cin >> input[j];
            range[j + 1] = range[j] + input[j];
        }
        char type = 0;
        int l, r;
        for (int j = 0; j < q; j++)
        {
            long long sum = 0;
            cin >> type >> l >> r;
            if (type == 'U')
            {
                for (int k = l; k < n + 1; k++)
                {
                    range[k] += r - input[l - 1];
                }
                input[l - 1] = r;
            }
            else
            {
                sum = range[r] - range[l - 1];
                int a = *min_element(range.begin(), range.begin() + l - 1);
                if (a < range[l - 1])
                    sum = range[r] - a;
                if (r < n - 1)
                {
                    int b = *max_element(range.begin() + r + 1, range.end());
                    if (b > range[r])
                        sum += b;
                }
                cout << sum << '\n';  
            }
        }
    }
    return 0;
}