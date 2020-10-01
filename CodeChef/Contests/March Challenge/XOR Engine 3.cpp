#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,q,p,o,c,h;
        cin>>n>>q;
        long long int a[n];
        int eve=0,odd=0;
        for(int i=0;i<n;i++)
        {
            c=0;
            cin>>a[i];
            while(a[i])
            {
                a[i]=a[i]&(a[i]-1);
                c++;
            }
            if(c%2==0)  eve++;
            else odd++;
        }
        while(q--)
        {
            cin>>p;
            c=0;
            while(p)
            {
                p=p&(p-1);
                c++;
            }
            if(c%2==0) cout<<eve<<" "<<odd<<'\n';
            else cout<<odd<<" "<<eve<<'\n';
        }
    }
    return 0;
}
