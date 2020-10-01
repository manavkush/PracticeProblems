#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        vi v0,v1;
        re(i,n)
        {
            cin>>a[i];
        }
        re(i,n)
        {
            int temp;
            cin>>temp;
            if(temp==0)
                v0.push_back(a[i]);
            else v1.push_back(a[i]);
        }
        if(is_sorted(v0.begin(),v0.end())&&is_sorted(v1.begin(),v1.end()))
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
                
    }
}