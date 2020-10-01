#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vlli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=a;i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    int n,i,j;
    lli sum;
    cin>>n;
    int a[n+2];
    re(i,n)
        cin>>a[i];

    lli base=10000000;
    re(i,n)
    {
        sum=0;
        re(j,n)
        {
            if(j>i)
                sum+=4*j*a[j];
            else    sum+=4*i*a[j];
        }
        if(sum<base)
            base=sum;
        //   cout<<sum<<"\t";
    }
    cout<<base;

}
