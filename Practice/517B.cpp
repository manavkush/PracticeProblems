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
{   FASTIO;
    int n;
    cin>>n;
    int a[n-1],b[n-1],t[n];
    re(i,n-1)
    cin>>a[i];
    re(i,n-1)
    cin>>b[i];

  /*  unordered_set<int> s;
    //====================================False Case =====
    if(a[0]<b[0]||(a[0]==2&&b[0]==1))
    {   cout<<"NO";
        return 0;
    }
    */
    int i,flag,j;

    re(p,4)
    {   re(q,4)
        {   if((p|q)==a[0]&& (p&q)==b[0])
            {   t[0]=p;
                t[1]=q;

                for(i=2; i<n; i++)
                {   flag=0;
                    re(j,4)
                    {
                              if( (t[i-1] | j) == a[i-1]   &&  (t[i-1]&j) == b[i-1] )
                              {   flag=1;
                                    t[i]=j;
                                    //break;
                              }
                    }
                    if(!flag)
                        break;

                }
                if(i==n)
                {
                      cout<<"YES\n";
                      for(int x : t)
                              cout<<x<<" ";
                        return 0;
                }

            }
        }
    }
    cout<<"NO";

}
