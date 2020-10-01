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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        re(i,n)
            cin>>a[i];
        vi v;
        v.push_back(a[0]);
        re1(i,1,n-2)
        {
            if(a[i]>a[i-1]&&a[i]>a[i+1])
                v.push_back(a[i]);
            else if(a[i]<a[i-1]&&a[i]<a[i+1])
                v.push_back(a[i]);
        }
        v.push_back(a[n-1]);
        cout<<v.size()<<endl;
        for(auto x:v)
            cout<<x<<" ";
        cout<<endl;
    }
}