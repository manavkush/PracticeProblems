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
        int n;
        cin >> n;
        vi a(n);
        vi b(n);
        vi s;
        re(i, n)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                s.push_back(i);
            }
        }
        if (s.empty())
        {
            cout << 0 << endl;
            a.clear();
            b.clear();
            s.clear();
            continue;
        }
        lli sum = 1;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i + 1] - s[i] > 1)
                sum += 1;
        }
        cout << sum << endl;
        a.clear();
        b.clear();
        s.clear();
    }
}