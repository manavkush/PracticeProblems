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
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
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
    int b[n];
    set<pair<int,int>> s;
    re(i,n)
    {
        cin>>a[i];
    }
    re(i,n)
    {
        cin>>b[i];
        s.insert(mp(a[i]-b[i],i));
    }
    int count=0;
    lli sum=0;
    for(auto it=s.begin();it!=s.end();it++)
    {
        if(count<k)
        {
            sum+=a[it->second];
            count++;
        }
        else if(it->first<=0)
        {
            sum+=a[it->second];
        }
        else 
        {
            sum+=b[it->second];
        }
    }
    cout<<sum;
}