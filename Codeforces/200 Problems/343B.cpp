#include<bits/stdc++.h>
using namespace std;
struct data
{
    char gender;
    int begin;
    int end;
};
int main()
{
    int n;
    cin>>n;
    data d[n];
    for(int i=0;i<n;i++)
    {
        cin>>d[i].gender;
        cin>>d[i].begin;
        cin>>d[i].end;
    }
    int max=0;
    for(int i=1;i<=366;i++)
    {
        int m=0,f=0;
        for(int j=0;j<n;j++)
        {
            if(d[j].begin<=i&&d[j].end>=i)
            {
                if(d[j].gender=='F')
                    f++;
                if(d[j].gender=='M')
                    m++;
            }
        }
        if(max<min(f,m))
            max=min(f,m);
    }
    cout<<max*2;
    
}