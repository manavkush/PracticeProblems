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
    lli n,k;
    cin>>n>>k;
    if(k<3||k>2*n-1)
    {
          cout<<0;
          return 0;
    }

    if(k<=n)
    {
          cout<<(k-1)/2;
          return 0;
    }

    cout<<(2*n+1-k)/2;
}
