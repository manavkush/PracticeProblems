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
    lli n,k,tmp,i;
    cin>>n>>k;
    lli x=(n>k)?n:k;
    lli num[x]={ };

    set <lli> s;

    re(i,n)
    {
        cin>>tmp;
        s.insert(tmp);
    }
    set<lli>::iterator itr2=s.begin();
    set<lli>::iterator itr=s.begin();
    num[0]=*itr;
    itr++;
    i=1;
    while(itr!=s.end())
    {
        num[i]=*itr-*itr2;
        i++;
        itr++;
        itr2++;
    }
    for(i=0;i<k;i++)
            cout<<num[i]<<"\n";






}
