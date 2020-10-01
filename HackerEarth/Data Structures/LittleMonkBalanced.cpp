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
        int n,i,ans,res;
        cin>>n;
        int x[n];
        re(i,n)
                cin>>x[i];
        stack <int> s;
        ans=0;
        s.push(-1);
        for(i=0;i<n;i++)
        {
                if(x[i]>0)
                {
                        s.push(i);
                }
                else
                {
                        int top=s.top();
                        s.pop();
                        if(x[top]==-1*x[i])
                        {
                                if(!s.empty())
                                {
                                res=i-s.top();
                                ans=max(res,ans);
                                }
                                else
                                        s.push(i);
                        }
                        else
                                s.push(i);
                }
        }
        cout<<ans;

}
