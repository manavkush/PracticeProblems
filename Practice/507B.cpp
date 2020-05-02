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
      int n,i,k,offset,count;
      cin>>n>>k;
      if(k==0)
      {
            cout<<n<<"\n";
            for(i=1;i<=n;i++)
                  cout<<i<<" ";
            return 0;
      }
      /*
      if(n==2*k+1)
      {
            cout<<k+1;
            return 0;
      }
      */

      if(2*k+1>=n)
      {
            cout<<1<<"\n"<<(n/2)+1;
            return 0;
      }
      else if(n==4*k+2)
      {
            cout<<"2\n"<<k+1<<" "<<3*k+1;
            return 0;
      }
      else if(n<4*k+2&&n>=3*k+2)
      {
            cout<<"2\n"<<k+1<<" "<<3*k+2;
            return 0;
      }
      else if(n<3*k+2)
      {
            cout<<"2\n"<<n-(2*k+1)<<" "<<n;
            return 0;
      }
      if(n>4*k+2)
      {
            offset=(n%(2*k+1));
            count=n/(2*k+1);
            if(offset==0)
            {
                  cout<<count<<"\n";
                  for(i=0;i<count;i++)
                  {
                        cout<<(k+1)+(2*k+1)*i<<" ";
                  }
                  return 0;
            }
            else if(offset>=k+1)
            {
                  cout<<count+1<<"\n";
                  for(i=0;i<=count;i++)
                  {
                        cout<<(k+1)+(2*k+1)*i<<" ";
                  }

            }
            else
            {
                  cout<<count+1<<"\n";
                  cout<<offset<<" ";
                  for(i=1;i<count;i++)
                  {
                        cout<<offset+(2*k+1)*i<<" ";
                  }
                  cout<<n;
            }
      }


}
