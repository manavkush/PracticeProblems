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
        string str;
        cin>>str;
        stack <int> s;
        s.push(-1);
        int n=str.size();
        cout<<n<<endl;
        int ans=0,res;
        re(i,n)
        {
            if(str[i]=='(')
                s.push(i);
            else
            {
                int top=s.top();
                s.pop();
                if(s.empty())
                    s.push(i);
                else
                {
                    if(str[top]=='(')
                    {
                        res=i-s.top();
                       ans=max(ans,res);
                    }
                }

            }
             cout<<s.top()<<" ";
        }
        cout<<endl<<ans;

}
