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
    lli a,b,x,y,d,i,j;

    cin>>a>>b>>x>>y;

    d=__gcd(x,y);
    x=x/d;
    y=y/d;

    i=a/x;
    j=b/y;

    cout<<min(i,j);
}
