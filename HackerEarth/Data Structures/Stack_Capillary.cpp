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
        int a[n];
        re(i,n)
                cin>>a[i];
        si s,t;
        re(i,n)
        {
                s.push(a[n-i-1]);
                t.push(a[i]);
        }

        re(i,2*n)
        {
                if(s.empty()||t.empty())
                        break;

                if(s.top()>t.top())
                {
                        cout<<1<<" ";
                        t.pop();
                }
                else if(t.top()>s.top())
                {
                        cout<<2<<" ";
                        s.pop();
                }
                else
                {
                        s.pop();
                        t.pop();
                        cout<<0<<" ";
                }
        }

}
