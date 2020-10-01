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
        int n;
        cin>>n;
        int a[n],i;
        re(i,n)
                cin>>a[i];
        si s;
        vi v1;
        vi v2(n,-1);
        set <pair <lli,lli> > st;
        re(i,n)
        {
                if(s.empty())
                {
                        v1.push_back(-1);
                        s.push(i);
                }
                else
                {
                        while(a[s.top()]<a[i])
                        {
                                v1[s.top()]=i;
                                s.pop();
                                if(s.empty())
                                        break;
                        }
                        s.push(i);
                        v1.push_back(-1);
                }
        }
        while(!s.empty())
                s.pop();
        for(i=n-1;i>=0;i--)
        {
                if(s.empty())
                {
                        s.push(i);
                }
                else
                {
                        while(a[s.top()]<a[i])
                        {
                                v2[s.top()]=i;
                                s.pop();
                                if(s.empty())
                                        break;
                        }
                        s.push(i);
                }
        }

       re(i,n)
       {
               if(v1[i]==-1)
                        continue;
                st.insert(   mp(i,v1[i])   );

       }
       cout<<st.size();
}
