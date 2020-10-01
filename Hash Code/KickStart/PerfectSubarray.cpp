#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long int lli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)

int main()
{
        FASTIO;
        int t;
        cin>>t;
        re(m,t)
        {
            lli count=0;
            int n;
            cin>>n;
            ld a[n];
            re(i,n)
                cin>>a[i];
            lli sum;
            re(i,n)
            {   sum=a[i];
                long double sr = sqrt(sum);
                if ((sr - floor(sr)) == 0)
                    count++;

                re1(j,i+1,n-1)
                {
                    sum+=a[j];
                    sr= sqrt(sum);
                    if ((sr - floor(sr)) == 0)
                    count++;

                }
            }

             cout<<"Case #"<<m+1<<": "<<count<<endl;

        }
}
