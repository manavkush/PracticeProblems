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
    lli n,k;

    string s;
    cin>>n;
    cin>>s;

    if(n==1)
    {
          cout<<"Yes";
          return 0;
    }

    sort(s.begin(), s.end());
    for(int i=0;i<n-1;i++)
    {
          if(s[i]==s[i+1])
          {
                cout<<"Yes";
                return 0;
          }
    }
    cout<<"No";

}
