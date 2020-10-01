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
        int n,i;
        cin>>n;
        lli b[n];
        re(i,n)         cin>>b[i];

        stack <lli> s;

        vlli v;
        for(i=0;i<n;i++)
        {
                if(s.empty())
                {
                        s.push(i);
                        v.push_back(-1);
                }
                else
                {
                        while(b[i]>b[s.top()])
                        {
                                v[s.top()]=i;
                                s.pop();
                                if(s.empty())
                                        break;
                        }
                        s.push(i);
                        v.push_back(-1);
                }

        }



        re(i,n)
        {
                if(v[i]==-1)
                {
                        cout<<"-1 ";
                }
                else
                {
                        int j=v[i];
                        lli c=-1;
                        for(int k=j+1;k<n;k++)
                        {
                                if(b[k]<b[j])
                                {
                                        c=b[k];
                                         break;
                                }
                        }
                        cout<<c<<" ";
                }
        }

}
