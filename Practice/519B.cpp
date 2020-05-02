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
{
    FASTIO;
    vector<int>vec;
    int n,i,j;
    cin>>n;
    int b[n];
    re(i,n)
        cin>>b[i];
    int arr[n];

    for(i=1;i<n;i++)
        arr[i]=b[i]-b[i-1];

    arr[0]=b[0];

    for(i=1;i<=n;i++)
    {
        int flag=1;
        for(j=0;j+i<n;j++)
        {
            if(arr[j]!=arr[i+j])
            {
                flag=0;
                break;
            }
        }
        if(flag)
            vec.push_back(i);
    }


        cout<<vec.size()<<"\n";
        for(i=0;i<vec.size();i++)
            cout<<vec[i]<<" ";

}
