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
        int i,n;
        cin>>n;
        int b[n];
        re(i,n)
        cin>>b[i];
        stack<int> s;
        vector<int>v,p;
        re(i,n)
        {
                if(s.empty())
                {
                        s.push(i);
                        v.push_back(-1);
                }
                else
                {
                        while(b[i]<b[s.top()])
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
        //re(i,n)
        //       cout<<v[i]<<" ";

        i=0;
        p.push_back(0);
        while(1)
        {
                if(v[i]==-1)
                        break;
                i=v[i];
                p.push_back(i);
        }
        int itr=p.size()-1;

        for(i=n-1;i>=0;i--)
        {
                if(i>=p[itr])
                        cout<<b[p[itr]]<<" ";
                else
                {
                        itr--;
                        cout<<b[p[itr]]<<" ";
                }
        }

}
