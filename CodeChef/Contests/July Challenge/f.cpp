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
int setBitNumber(int n)
{
    if (n == 0)
        return 0;

    int msb = 0;
    while (n != 0)
    {
        n = n / 2;
        msb++;
    }

    return msb;
}
int main()
{
    FIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vi a(n);
        vi b(n);
        vector<vector<int> > v;
        re(i, n)
                cin >>a[i];

        sort(a.begin(), a.end());
        b = a;
        if (x >= a[n - 1])
        {
            cout << n << endl;
            a.clear();
            b.clear();
            continue;
        }
        else
        {
            vi temp;
            temp.push_back(0);
            re1(i,1,n-1)
            {
                if(a[i]<=2*a[i-1])
                {
                    temp.push_back(i);
                }
                else
                {
                    v.push_back(temp);
                    temp.clear();
                    temp.push_back(i);
                }
            }
            if(!temp.empty())
                v.push_back(temp);
            
        }
    }
}