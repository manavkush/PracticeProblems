#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define re(i,n)        for(int i=0;i<(n);i++)
#define FOR(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    int t,temp;
    map<int,int> mp;
    cin>>t;
    while(t--)
    {
          int n;
          cin>>n;

          re(i,n)
          {
                cin>>temp;
                mp[temp]++;
          }
          map<int,int>::iterator itr;
          int max=(mp.begin())->second;
          for(itr=mp.begin();itr!=mp.end();itr++)
          {
                if(itr->second>max)
                  max=itr->second;
          }
          if(max>mp.size())
               cout<<mp.size();
          else if(max==mp.size())
                  cout<<max-1;
          else    cout<<max;

         cout<<"\n";
         mp.clear();
    }

}
