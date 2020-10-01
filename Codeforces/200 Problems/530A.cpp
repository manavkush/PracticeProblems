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

int main()
{
    FASTIO;
    long int w,h,u1,d1,u2,d2,i;
    cin>>w>>h>>u1>>d1>>u2>>d2;
    for(i=h;i>=0;i--)
    {
        w+=i;
        if(i==d1)
        {
            w=w-u1;
            if(w<0)
                w=0;
        }
        else if(i==d2)
        {
            w=w-u2;
            if(w<0)
                w=0;
        }

       // cout<<w<<" ";
    }
    cout<<w;
}
