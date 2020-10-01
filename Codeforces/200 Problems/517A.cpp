#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define re(i,n)        for(int i=0;i<(n);i++)
#define FOR(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    int w,h,k;
    lli sum=0;
    cin>>w>>h>>k;
    re(i,k)
    {
        sum+=2*(w  -  4*i + h - 4*i  -  2);
    }
    cout<<sum;
}
