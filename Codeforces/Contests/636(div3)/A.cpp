#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define REP(i,n)        for(int i=0;i<(n);i++)
#define FOR(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

lli power(lli a, lli b)
{
    lli sum=1;
    for(int i=0;i<b;i++)
    {
        sum*=a;
    }
    return sum;
}

int main()
{
    FASTIO;
    lli t,n,i,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        k=2;
        while(1)
        {
            if(n%(power(2,k)-1)==0)
                break;
            k++;
        }
        cout<<n/(power(2,k)-1)<<"\n";
    }

}
