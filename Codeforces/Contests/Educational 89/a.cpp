#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        lli ans=0;
        
        if(max(a,b)>=2*(min(a,b)))
        {
            cout<<min(a,b)<<endl;
            continue;
        }
        int v=min(a,b); 
        ans=(v/3)*2;
        a=a-(v/3)*3;
        b=b-(v/3)*3;

        if(min(a,b)==0)
            cout<<ans<<endl;
        else if(min(a,b)==1&&max(a,b)>=2)
            cout<<ans+1<<endl;
        
        else if(min(a,b)==2&&max(a,b)<4)
            cout<<ans+1<<endl;
        
        else if(min(a,b)==2&&max(a,b)>=4)
            cout<<ans+2<<endl;
        else cout<<ans<<endl;
    }

}