#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FASTIO                       \
        ios::sync_with_stdio(false); \
        cin.tie(0);                  \
        cout.tie(0)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i, n) for (int i = 0; i < (n); i++)
#define re1(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)

int main()
{
        FASTIO;
        vector<int> v1, v2;
        int t, n, x;
        cin >> t;
        while (t--)
        {
                cin >> n >> x;
                int a[n];
                int odd = 0, even = 0;
                re(i, n)
                {
                        cin >> a[i];
                        if (a[i] & 1)
                                odd++;
                        else
                                even++;
                }
                // if(!odd)
                // {
                //         cout<<"NO"<<endl;
                //         continue;
                // }
                int flag = 0;
                for (int i = 1; i <= odd && i <= x; i = i + 2)
                {
                        if (x - i <= even)
                        {
                                cout << "YES\n";
                                flag = 1;
                                break;
                        }
                }
                if (!flag)
                {
                        cout << "NO\n";
                }
        }
}
