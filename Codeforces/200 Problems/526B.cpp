#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vlli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define re(i,n)        for(lli i=0;i<(n);i++)
#define re1(i,a,b)       for(lli i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    cout<<fixed;
    lli n,s;
    cin>>n>>s;
    lli a[n];
    lli sum=0,base,i;
    re(i,n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum<s)
    {cout<<"-1";
        return 0;
    }
    else if(sum==s)
    {
        cout<<"0";
        return 0;
    }
    sort(a,a+n);
    base=0;
    re(i,n)
           base+=a[i]-a[0];

    if(base>=s)
        cout<<int(a[0]);
    else
    {
        for( i=1;;i++)
        {
            if(base+(i*n)>=s)
                break;
        }
        cout<<a[0]-i;
    }



}
