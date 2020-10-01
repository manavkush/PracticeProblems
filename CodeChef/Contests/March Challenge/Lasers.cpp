#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,q,i,counts,x1,x2;
    long long int arr[100000],y;
    cin>>t;
    while(t--)
    {

        cin>>n>>q;


                for(i=0;i<n;i++)
                    cin>>arr[i];
        while(q--)
        {

                cin>>x1>>x2>>y;
                counts=0;

                for(i=x1-1;i<x2-1;i++)
                {

                    if(i==x1-1)
                    {
                        if((arr[i]>=y&&arr[i+1]<=y)||(arr[i]<=y&&arr[i+1]>=y))
                           counts++;
                    }
                    else if(i==x2-2)
                    {
                        if((arr[i]>=y&&arr[i+1]<=y)||(arr[i]<=y&&arr[i+1]>=y))
                           counts++;
                    }

                    else if(arr[i]>=y&&arr[i+1]<=y)
                        counts++;
                    else if(arr[i]<=y&&arr[i+1]>=y)
                        counts++;
                }
                cout<<counts<<"\n";

        }
    }
    return 0;
}
