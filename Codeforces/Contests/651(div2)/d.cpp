#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
    int n,k;
    cin>>n>>k;
    int a[n];
    set < pair<int ,int> > s;
    set <int> s1;
    vi v;
    re(i,n)
    {
        cin>>a[i];
        s.insert(mp(a[i],i));
    }
    int count=0;
    for(auto x=s.begin();count<k;x++)
    {
        s1.insert(x->second);
        count++;
    }
    for(auto x:s1)
    {
        v.push_back(x);
    }
    int max1=1;
    int max2=1;
    re(i,v.size())
        cout<<v[i]<<" ";
    cout<<endl;
    for(int i=0;i<v.size();i=i+2)
    {
        if(a[v[i]]>max1)
            max1=a[v[i]];
    }
    for(int i=1;i<v.size();i=i+2)
    {
        if(a[v[i]]>max2)
            max2=a[v[i]];
    }
    cout<<min(max1,max2)<<endl;
    

}