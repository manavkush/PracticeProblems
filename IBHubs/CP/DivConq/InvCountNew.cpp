#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vlli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"
#define pb push_back
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

lli countsplit(lli arr1[ ],lli arr2[ ], lli arr[ ], lli n)
{
    lli i=0,j=0,q=0,countsplit=0;
    while((i<n/2)&&(j<n-n/2))
    {
        if(arr1[i]<=arr2[j])
            arr[q++] = arr1[i++];

        else
            {
            arr[q++]=arr2[j++];
            countsplit+=(n/2)-i;
            }
    }
    if(i>=n/2)
        {
            for(;j<n-n/2;j++)
                arr[q++]=(arr2[j]);
        }

    else if(j>=n-n/2)
    {
        for(;i<n/2;i++)
            arr[q++]=(arr1[i]);
    }
    return countsplit;
}

lli invertcount(lli  arr[],lli n)
{
    if(n==1)
        return 0;
    lli ar1[n/2],ar2[n-(n/2)];
    re(i,n/2)
        ar1[i]=arr[i];
    re(i,n-n/2)
    {
        ar2[i]=arr[i+n/2];
    }
    lli x,y,z;
    x=invertcount(ar1,n/2);
    y=invertcount(ar2,n-n/2);
    z=countsplit(ar1,ar2,arr,n);
    return x+y+z;
}
int main()
{
    FASTIO;
    lli num[100000];
    int n;
    cin>>n;
    re(i,n)
        cin>>num[i];
    lli x=invertcount(num,n);
    cout<<x;
}
