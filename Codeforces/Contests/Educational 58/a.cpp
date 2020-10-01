#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
        FASTIO;
        int q;
        cin>>q;
        while(q--)
        {
                int l,r,d;
                cin>>l>>r>>d;
                int num=d;
                int i=1;

                if(d<l||d>r)
                        cout<<d<<endl;
                else
                {
                        cout<<d+r-r%d<<endl;
                }

        }


}
