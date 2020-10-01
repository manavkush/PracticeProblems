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
        string str;
        cin>>str;
        int n=str.size();
        stack <int>s;
        for(int i=0;i<=n;i++)
        {
                        s.push(i+1);

                        if(i==n||str[i]=='I')
                        {
                                while(!s.empty())
                                {
                                        cout<<s.top()<<" ";
                                        s.pop();
                                }
                        }
        }

}
