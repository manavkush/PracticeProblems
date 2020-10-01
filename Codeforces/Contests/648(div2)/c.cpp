#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FIO;
    int n;
    cin>>n;
    int a[n];
    map<int,int> m;
    re(i,n)
    {
        cin>>a[i];
        m[a[i]]=i;
    }
    map<int,int> mp;
    int val;
    re(i,n)
    {
        int temp;
        cin>>temp;
        int id=m[temp]-i;
        if(id<0)
            id=id+n;
        mp[id]++;  
    }
    int max=1;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(max<(it->second))
            max=it->second;
    }
    cout<<max;
}