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
        int n;
        cin>>n;
        int b[n];
        int res,ans,j;
        re(i,n)         cin>>b[i];

        stack <int> s;
        vi v;
        re(i,n)
    {
        if(s.empty())
        {
                s.push(i);
                v.push_back(-1);
        }
        else
        {
            while(  b[i]>b[ s.top() ]  )
            {
                j=s.top();
                v[j]=i;
                s.pop();
                if(s.empty())
                    break;
            }
        s.push(i);
        v.push_back(-1);
        }
    }


        ans=b[n-1];

        re(i,n)
        {
                j=i;
                res=b[j];
                while(1)
                {
                        if(v[j]==-1)
                                break;
                        else
                        {
                                j=v[j];
                                res=res^b[j];
                        }
                }

                ans = max(ans,res);
        }
        cout<<ans;

}
