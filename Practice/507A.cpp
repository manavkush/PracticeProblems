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
    int a,b,n,i;
    cin>>n>>a>>b;
    int arr[n],low,sum=0;
    int cost[2]={a,b};

    if(a<b)
      low=a;
    else low=b;

    for(i=0;i<n;i++)
        cin>>arr[i];

          for(i=0;i<n/2;i++)
      {
            if(arr[i]==1&&arr[n-1-i]==1)
                  ;

            else if(arr[i]==0&&arr[n-1-i]==0)
                  ;

            else if(arr[i]==2)
            {
                  if(arr[n-i-1]!=2)
                  sum=sum+cost[arr[n-1-i]];
                  else
                        sum=sum+2*low;
            }
            else if(arr[n-i-1]==2)
                  sum=sum+cost[arr[i]];
            else
            {
                  cout<<-1;
                  return 0;
            }
      }
      if(n%2!=0)
      {
            if(arr[(n/2)]==2)
                  sum+=low;
      }
      cout<<sum;
}
