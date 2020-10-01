#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define REP(i,n)        for(int i=0;i<(n);i++)
#define FOR(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    int n,d,m,i,x,y;
    cin>>n>>d;
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;

        if(  x+y<=2*n-d    &&   x+y>=d   &&   y<=x+d  &&  y>=x-d  )
        {
            cout<<"YES\n";
        }
        else
        cout<<"NO\n";
    }

}
