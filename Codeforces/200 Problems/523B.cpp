#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vlli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    lli n,m;
    cin>>n>>m;
    vlli num;
    lli sum=0,temp,i,y;
    re(i,n)
    {
        cin>>temp;
        num.push_back(temp);
        sum+=temp;
    }

    sort(num.begin(), num.end());
    y=0;
    for(i=0;i<n;i++)
    {
        if(num[i]>y)
            y++;
    }
    sum=sum-(n+num[n-1]-y);
    cout<<sum;

}
