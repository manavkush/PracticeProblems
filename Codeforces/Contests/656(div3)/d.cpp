#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define endl "\n"

#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
string str;
int agood(int f,int l,char c)
{
    if(f==l)
    {
        if(str[f]==c)
            return 0;
        else return 1;
    }
    int mid=(f+l)/2;
    int a=0,b=0;
    
    re1(i,f,mid)
    {
        if(str[i]!=c)
            a++;
    }
    re1(i,mid+1,l)
    {
        if(str[i]!=c)
            b++;
    }

        int a1=agood(f,mid,c+1);
        int b1=agood(mid+1,l,c+1);
    
    return min(a+b1,b+a1);
}
int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin>>str;
        int ans=agood(0,n-1,'a');
        cout<<ans<<endl;        
    }
}