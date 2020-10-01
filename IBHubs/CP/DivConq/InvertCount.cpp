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
class ret
{
public:
    lli count;
    vector<int> v;
};

ret invertutility(vi a,vi b)
{
    int i=0; int j=0;
    ret r;
    r.count=0;
    while((i<a.size())&&(j<b.size()))
    {
        if(a[i]<=b[j])
        {
            r.v.push_back(a[i]);
            i++;
        }
        else
        {
            r.count+=(a.size()-i);
            r.v.push_back(b[j]);
            j++;
        }
        
    }
    while(i<a.size())
    {
        r.v.push_back(a[i]);
        i++;
    }
    while(j<b.size())
    {
        r.v.push_back(b[j]);
        j++;
    }
    return r;
}

ret invertcount(vi a,int f, int l)
{
    if(f==l)
    {
        ret r;
        r.count=0;
        r.v.push_back(a[f]);
        return r;
    }
    else
    {
        ret r1,r2,r3,ans;
        int mid=(f+l)/2;
        vi v1,v2;

        for(int i=f;i<=mid;i++)
            v1.push_back(a[i]);
        for(int i=mid+1;i<=l;i++)
            v2.push_back(a[i]);
        
        r1=invertcount(v1,f,mid);
        r2=invertcount(v2,mid+1,l);
        r3=invertutility(r1.v,r2.v);
        ans.count=(r1.count+r2.count+r3.count);
        ans.v=r3.v;
        return ans;
    }
    
}
int main()
{
    FIO;
    int n;
    cin>>n;
    vi a(n);
    re(i,n)
        cin>>a[i];
    ret ans=invertcount(a,0,n-1);
    cout<<ans.count<<endl;
    for(auto x: ans.v)
        cout<<x<<" ";
}