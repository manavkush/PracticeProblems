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
    long int n,k,big;
    long int sum=0,req;
    map <int,int> mp;
    cin>>n>>k;
    re(i,n)
    {
        cin>>req;
        mp[req]++;
    }
    map<int,int>::iterator itr=mp.begin();
    big=itr->second;
    for(itr=mp.begin();itr!=mp.end();itr++)
        if(itr->second>big)
            big=itr->second;

    //cout<<big<<"\t";
    if(big%k==0)
        req=big;
    else    req=(big-big%k)+k;
    for(itr=mp.begin();itr!=mp.end();itr++)
        sum=sum+(req-(itr->second));
    cout<<sum;

}
