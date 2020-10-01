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
        re(j,t)
        {
            int n,k;
            cin>>n>>k;
            int a[n];
            vi vec;
            re(i,n)
            {
                cin>>a[i];
                if(a[i]==k)
                    vec.push_back(i);
            }
            int count=0;
            int flag;
            for(auto x: vec)
            {
                flag=0;
                re1(i,x+1,x+k-1)
                {
                    if(a[i-1]-a[i]!=1)
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                    count++;
            }

            cout<<"Case #"<<j+1<<": "<<count<<endl;




            vec.clear();



        }




}
