#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define re(i,n)        for(int i=0;i<(n);i++)
#define FOR(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

lli pow(int x,lli count)
{
    lli sum=1;
    re(i,count)
    {
        sum*=x;
    }
    return sum;
}

int main()
{
    FASTIO;
    int t;
    cin>>t;
    lli count,a;
    re(i,t)
    {
        cin>>a;
        count=0;
        while(a)
        {
            a=a&(a-1);
            count++;
        }
            cout<<pow(2,count)<<"\n";
    }

}
