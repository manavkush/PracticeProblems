#include <bits/stdc++.h>
using namespace std;


#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin>>t;
    while (t--)
    {
        int n,x,c,d;
        c=d=0;
        long long  int sum=0;
        cin>>n>>x;
        int a[n];
        re(i,n)
        {
            int temp;
            cin>>temp;
            a[i]=temp%x;
            sum=sum+a[i];
        }
        if(sum%x!=0)
        {
            cout<<n<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if (a[i]!=0)
            {
                c=i+1;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]!=0)
            {
                d=n-i;
                break;
            }
        }
        if(c==0||d==0)
            cout<<-1<<endl;
        else cout<<n-min(c,d)<<endl;
            
        

    }
    
}