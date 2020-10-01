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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int freq[n+1]={0};

        re(i,n)     
        {
            cin>>a[i];
            freq[a[i]]++;
        }
        set<int> s;
        re(i,n+1)
        {
            if(freq[i]==0)
            {
                s.insert(i);
            }
        }
        int k=0;
        vector<int> v;
        
        for(int i=0;i<2*n&&(!s.empty());i++)
        {
            k++;
            int t=*(s.begin());
            freq[t]++;
            s.erase(t);
            if( (--freq[a[t]] )==0 )
            {
                s.insert(a[t]);
            }
            a[t]=t;
            v.push_back(t);
        }
        cout<<k<<endl;
        for(auto x:v)
            cout<<x<<" ";
        cout<<endl;
        s.clear();
        v.clear();
    }
}