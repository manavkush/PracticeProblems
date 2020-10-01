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
    int n;
    cin>>n;
    int a[n];
    re(i,n)
        cin>>a[i];
    sort(a,a+n);
    int used=0;
    int ans=0;
    while(used<n)
    {
        int reset=0;
        ans++;
        for(int i=0;i<n;i++)
        {
            if(a[i]>=reset)
            {
                reset++;
                used++;
                a[i]=-1;
            }           
        }

    }
    cout<<ans;
    
}