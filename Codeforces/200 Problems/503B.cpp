#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define rep(i,n)        for(int i=0;i<(n);i++)
#define FOR(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
     FASTIO;
      int n,arr[1005];
      cin>>n;
      unordered_set <int> set;
      rep(i,n)
            cin>>arr[i];

      rep(j,n)
      {
            int i=j;
            set.insert(j+1);
            while(1)
            {
                  if(set.find(arr[i])!=set.end())
                  {
                        cout<<arr[i]<<" ";
                        set.clear();
                        break;
                  }
                  else
                  {
                        set.insert(arr[i]);
                        i=arr[i]-1;
                  }
            }
      }

}
