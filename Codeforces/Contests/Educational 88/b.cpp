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
        int t;
        cin>>t;

        while(t--)
        {
                int sum1=0;
                int sum2=0;
                int n,m,x,y;
                cin>>n>>m>>x>>y;
                vector<string> v;
                string str;
                re(i,n)
                {
                        cin>>str;
                        v.push_back(str);
                }
                re(i,n)
                {
                        re(j,m)
                        {
                                if(v[i][j]=='.')
                                {
                                        int temp=j;
                                        int count=0;
                                        while(v[i][temp]=='.'&&temp<m)
                                        {
                                                count++;
                                                temp++;
                                        }
                                        sum2+=count/2;
                                        sum1+=count%2;
                                        j=temp-1;
                                }

                        }
                }
                if(2*x<=y)
                {
                        cout<<(sum1+sum2*2)*x<<endl;
                }
                else
                {
                        cout<<(sum1*x+sum2*y)<<endl;
                }
                v.clear();
        }

}
