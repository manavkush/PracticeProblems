#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i, n) for (int i = 0; i < (n); i++)
#define re1(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)

int main()
{
    FIO;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        string ans;
        map<char, int> m;
        m['R'] = 0;
        m['P'] = 0;
        m['S'] = 0;
        char c = 'P';
        re(i, n)
        {
            m[s[i]]++;
        }
        tr(it, m)
        {
            if (it->second > m[c])
            {
                c = it->first;
            }
        }
        if (c == 'R')
        {
            ans = string(n, 'P');
        }
        else if (c == 'P')
        {
            ans = string(n, 'S');
        }
        else
        {
            ans = string(n, 'R');
        }

        cout << ans << endl;
    }
}