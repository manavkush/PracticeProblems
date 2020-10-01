#include <bits/stdc++.h>
using namespace std;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)


int main()
{
        FASTIO;
        int t,i;
        cin>>t;
        for(int m=0;m<t;m++)
        {
            int n,q;
            cin>>n>>q;
            int a[n];

         for(i=0;i<n;i++)
                cin>>a[i];
            long long int sum=0;
            for(i=0;i<q;i++)
            {
                char ch;
                int x,y;
                cin>>ch>>x>>y;
                if(ch=='U')
                    a[x-1]=y;
                else
                {
                    for(int j=x-1;j<=y-1;j++)
                    {
                        sum+=((j-x+1)%2 ? -1 : 1)*a[j]*(j-x+2);
                    }
                }
            }

            cout<<"Case #"<<m+1<<": "<<sum<<"\n";

        }




}
