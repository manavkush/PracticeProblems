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
lli pos(lli n)
        {
            if (n == 0)
                return 0;

            lli msb = 0;
            while (n != 0) {
                n = n / 2;
                msb++;
            }

            return ( msb);
        }

int main()
{
        FASTIO;
        int t;
        cin>>t;
        while(t--)
        {
                int64_t   n;
                cin>>n;
                int64_t   msb=pos(n);
                int64_t   sum=0;
                int64_t one=1;
                for(int64_t   i=0;i<msb;i++)
                {
                        if(n&(one<<i))
                        {
                                sum+=pow(2,i+1)-1;
                        }
                }
                cout<<sum<<endl;
        }

}
