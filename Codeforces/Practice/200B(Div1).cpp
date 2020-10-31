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
#define re(i,n)   for(int i=0;i<n;i++)
#define it(i,a)        for(auto i=a.begin();i!=a.end();i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
        FASTIO;
        string str;
        cin>>str;
        stack<char> s;
        int n=str.size();
        if(n%2)
        {
                cout<<"No";
                return 0;
        }
        re(i,n)
        {
                if(s.empty())
                {
                        s.push(str[i]);
                }
                else
                {
                        if(s.top()==str[i])
                                s.pop();
                        else
                        {
                                s.push(str[i]);
                        }
                }
        }
        cout<<(s.empty() ? "Yes" : "No");

}
