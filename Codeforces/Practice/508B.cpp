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
    lli n,i;
    cin>>n;
    if(n==1||n==2)
    {
        cout<<"No";
        return 0;
    }
    cout<<"Yes\n";

    cout<<(n+1)/2<<" ";

    for(i=1;i<=n;i=i+2)
        cout<<i<<" ";



    cout<<"\n"<<(n/2)<<" ";

    for(i=2;i<=n;i=i+2)
        cout<<i<<" ";

}
