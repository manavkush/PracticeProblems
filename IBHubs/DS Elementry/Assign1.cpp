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
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
        FASTIO;
        int n;
        cin>>n;
        int a[n][2];
        re(i,n)
        {
                cin>>a[i][0];
                cin>>a[i][1];
        }
        re(i,n)
        {
                if(a[i][0]<a[i][1])
                        continue;
                int sum=0,j=0,flag=0;

                re(count,n+1)
                {
                        if(i+j==n)
                                j=j-n;

                        sum+=a[i+j][0]-a[i+j][1];
                        if(sum<0)
                        {
                                flag=1;
                                break;
                        }
                        j++;
                }
                if(!flag)
                {
                        cout<<i;
                        return 0;
                }
        }
        cout<<-1;

}
