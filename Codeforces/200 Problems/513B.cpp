#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector <lli> vlli;

#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define REP(i,n)        for(int i=0;i<(n);i++)
#define FOR(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    lli n,sum,temp,carry;

    cin>>n;
    sum=0,carry=0;
   // if(n/10==0)
    //  cout<<"n";


    while((n/10)!=0)
    {
          temp=n%10;

          if(carry==1)
               sum+=10+temp-carry;

          else
          {
                if(temp==9)
                  sum=sum+9;
                else
                {
                      sum+=10+temp-carry;
                      carry=1;
                }
          }

          n=n/10;
    }
    sum=sum+n-carry;
    cout<<sum;

}
