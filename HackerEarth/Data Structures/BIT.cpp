#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll n, q;

vector<vector<int>> bit;

void update(int pos, int cn, int c)
{

    for (int i = pos; i <= n; i += (i & (-i)))
    {

        bit[i][c] += cn;
    }
}

vector<int> query(int l)
{

    vector<int> v(26, 0);

    for (int i = l; i > 0; i -= (i & (-i)))
    {

        for (int j = 0; j < 26; j++)
        {

            v[j] += bit[i][j];
        }
    }

    return v;
}

void solve()

{

    cin >> n >> q;

    string s;

    cin >> s;

    bit = vector<vector<int>>(1e5 + 5, vector<int>(26, 0));

    for (int i = 1; i <= n; i++)
    {

        int c = s[i - 1] - 'a';

        update(i, 1, c);
    }

    while (q--)
    {

        int t;
        cin >> t;

        if (t == 1)
        {

            int l;

            char c;

            cin >> l >> c;

            update(l, -1, s[l - 1] - 'a');

            s[l - 1] = c;

            update(l, 1, c - 'a');
        }
        else
        {

            int l, r;
            cin >> l >> r;

            vector<int> v1 = query(r);

            vector<int> v2 = query(l - 1);

            int c = 0;

            for (int i = 0; i < 26; i++)
            {

                v1[i] = v1[i] - v2[i];

                if (v1[i] % 2 == 1)
                    c++;

                // cout<<v1[i]<<" ";
            }

            // cout<<"\n";

            if (c > 1)
                cout << "no\n";

            else
                cout << "yes\n";
        }
    }
}

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int t = 1;

    // cin>>t;

    while (t--)

    {

        solve();
    }

    return 0;
}