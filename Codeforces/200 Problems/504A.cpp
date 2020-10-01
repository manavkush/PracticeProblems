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
    lli a,b,i=0;
    string str1,str2;
    cin>>a>>b;
    cin>>str1;
    cin>>str2;
    int flag=0;

    if(a>b+1)
    {
          cout<<"NO";
          return 0;
    }

    while(str1[i]!='*'&&i<a)
    {
          if(str1[i]!=str2[i])
          {
                  flag=1;
                  break;
          }
          i++;
    }

    if(flag==1)
    {
          cout<<"NO";
          return 0;
    }

    i=1;

    while(str1[a-i]!='*'&&i<=a)
    {
          if(str1[a-i]!=str2[b-i])
          {
                flag=1;
                break;
          }
          i++;
    }

    if(flag==1)
    {
          cout<<"NO";
          return 0;
    }

    if(str1[a-i]!='*')
    {
          if(a==b)
          {
                cout<<"YES";
                return 0;
          }
          else
          {
                cout<<"NO";
                return 0;
          }
    }
    else    cout<<"YES";
}
