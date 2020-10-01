#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    int t;
    cin>>t;
    while (t--)
    {
        set<int> sr;
        set<int> sc;
        int n,m;
        cin>>n>>m;
        int a[n][m];
        re(i,n)
        {
            re(j,m)
            {    cin>>a[i][j];
                if(a[i][j]==1)
                {
                    sr.insert(i);
                    sc.insert(j);
                }
            }
        }
            lli sum=min(n-sr.size(),m-sc.size());
            if(sum%2)
                cout<<"Ashish\n";
            else cout<<"Vivek\n";
    }
    
}