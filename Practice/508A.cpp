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
    int n,k,i;
    cin>>n>>k;
    unordered_map <char,int> mp;
    string str;
    cin>>str;
    for(i=0;i<n;i++)
    {
        mp[str[i]]++;
    }
    if(mp.size()!=k)
    {
        cout<<mp.size()<<" ";
        cout<<0;
        return 0;
    }
    int low=mp.begin()->second;
    unordered_map <char,int> ::iterator itr;
    for(itr=mp.begin();itr!=mp.end();itr++)
    {
        if(itr->second<low)
            low=itr->second;
    }
    cout<<low*k;

}
