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
    int n,i,sum,n1,count,min,mx;      cin>>n;
    // The idea is to get the prime factorization of the number and check if the highest power of the p.f. Then by dividing by 2 repeatedly;
    if(n==1)
    {
        cout<<1<<" "<<0;
        return 0;
    }
    map<int,int> mp;

    n1=n;
    while(n%2==0)
    {
        n/=2;
        mp[2]++;
    }
    for(i=3;i<=n1;i=i+2)
    {
        while(n%i==0)
        {   n=n/i;
            mp[i]++;    }
    }
    map<int,int>::iterator itr=mp.begin();
    min=itr->second;
    mx=min;

    sum=1;
    for(itr=mp.begin();itr!=mp.end();itr++)
    {
        if(itr->second>mx)
            mx=itr->second;
        else if(itr->second < min )
            min=itr->second;

        sum*=(itr->first);
    }
//============================CONDITIONS=============================
    if(mx==min&&(( mx&(mx-1)) == 0))
    {
        count=0;
        while(mx!=1)
        {
            mx=mx>>1;
            count++;
        }
        cout<<sum<<" "<<count;
    }
    else if((mx&(mx-1) )== 0)
    {
        count=1;
        while(mx!=1)
        {
            mx=mx>>1;
            count++;
        }
        cout<<sum<<" "<<count;
    }

    else
    {
        count=2;
        while(mx!=1)
        {
            mx=mx>>1;
            count++;
        }
        cout<<sum<<" "<<count;
    }
}

