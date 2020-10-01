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
     lli t,n,i,k;
    cin>>t;
    while(t--)
    {
        cin>>n;

        if((n/2)%2!=0)
            cout<<"NO\n";

        else
        {

            int arr[n];
            for(i=0;i<n/2;i++)
            {
                arr[i]=2*(i+1);
            }
            for(;i<n-1;i++)
            {
                arr[i]=2*(i-n/2+1)-1;
            }
            arr[n-1]=(n-1)+n/2;

            cout<<"YES\n";
            for(i=0;i<n;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
    }
}
