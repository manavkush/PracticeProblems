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
    int n,m,i,j;
    lli count=0;

    cin>>n>>m;
    int arr[n];

    for(i=0;i<n;i++)
           cin>>arr[i];

    sort(arr,arr+n);

    lli b=arr[n-1]+m;
    if(arr[0]==arr[n-1])
    {
        double m1=m;
        double n1=n;
        cout<<(arr[0]+ceil(m1/n1))<<" "<<b;
        return 0;
    }

    i=0;
    int flag=0;

    while(count<m)
    {
        if(i==n-1)
        {
            flag=1;
            break;
        }

        if(arr[i+1]==arr[i])
            i++;

        else
        {
            count=count+(arr[i+1]-arr[i])*(i+1);
            for(j=0;j<=i;j++)
                arr[j]=arr[i+1];
            i++;
        }
    }
    if(flag)
    {
        double m1=m;
        double c1=count;
        arr[0]=arr[0]+ceil((m1-c1)/n);
        cout<<arr[0]<<" "<<b;
        return 0;
    }
    else
    {
        cout<<arr[n-1]<<" "<<b;
    }
}
