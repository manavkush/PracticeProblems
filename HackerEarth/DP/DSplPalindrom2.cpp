#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[1002][1002];
ll b[1002][1002];

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        char c;
        string s;
        cin >> c;
        cin >> s;

        ll len = s.length();
        ll n = len;

        for (ll i = 0; i < n; i++)
        {
            ll j = 0, k = i;

            while (k < n)
            {
                if (i == 0)
                {
                    a[j][k] = (s[j] == c) ? 1 : 0;
                    b[j][k] = 1;
                }
                else
                {

                    if (s[j] != s[k])
                    {
                        a[j][k] = max(a[j + 1][k], a[j][k - 1]);
                        b[j][k] = max(b[j][k - 1], b[j + 1][k]);
                    }
                    else
                    {
                        ll midlen = k - j - 1;

                        if (s[j] == c)
                        {

                            if (midlen == 0)
                            {
                                b[j][k] = 2;
                                a[j][k] = 2;
                            }
                            else
                            {
                                b[j][k] = 2 + b[j + 1][k - 1];
                                a[j][k] = 2 + b[j + 1][k - 1];
                            }
                        }
                        else
                        {

                            if (midlen == 0)
                            {

                                b[j][k] = 2;
                                a[j][k] = 0;
                            }
                            else
                            {
                                b[j][k] = 2 + b[j + 1][k - 1];
                                a[j][k] = (a[j + 1][k - 1] == 0) ? 0 : a[j + 1][k - 1] + 2;
                            }
                        }
                    }
                }
                j++;
                k++;
            }
        }
        cout << a[0][n - 1] << endl;
    }
    return 0;
}