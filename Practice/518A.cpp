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
    lli n,m,k,l;
    cin>>n>>m>>k>>l;
    if(  (n-k<l)  ||  (n <m)   )
    {
          cout<<-1;
          return 0;
    }
    lli flag=0,x;
    long double l1=l,k1=k,m1=m;
    x=ceil((l1+k1)/m1);
    if(x<=n/m)
      cout<<x;
    else
      cout<<-1;


}
