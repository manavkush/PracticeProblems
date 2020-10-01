#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vlli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    int q;
    long double l,r;
    cin>>q;
    lli vl,vr;
    re(i,q)
    {
        cout<<fixed;
        cin>>l>>r;
        if(l==r)
        {
            if(int(l)%2==0)
            cout<<int(l)<<"\n";
            else    cout<<int(-1*l)<<"\n";
            continue;
        }
        lli l1=l,r1=r;
        if(l1%2)
            vl=ceil((l-1)/2);
        else vl=-ceil((l-1)/2);

        if(int(r)%2)
            vr=-ceil(r/2);
        else vr=ceil(r/2);

        cout<<vr-vl<<"\n";
    }
}
