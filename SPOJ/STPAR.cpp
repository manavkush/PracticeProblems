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
#define it(i,a)        for(auto i=a.begin();i!=a.end();i++)
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
        FASTIO;
        int n,temp;
        si s;
        vi v;
        while(1)
        {
                cin>>n;
                if(n==0)
                        break;
                re(i,n)
                {
                        cin>>temp;
                        if(s.empty())
                                s.push(temp);
                        else
                        {
                                while(temp>s.top())
                                {
                                        int top=s.top();
                                        v.push_back(top);
                                        s.pop();
                                        if(s.empty())
                                                break;
                                }
                                s.push(temp);
                        }
                }
                while(!s.empty())
                {
                        v.push_back(s.top());
                        s.pop();
                }

                int temp=0;
                re(i,n-1)
                {
                        if(v[i]>v[i+1])
                        {
                                temp=1;
                                break;
                        }
                }

                if(temp)
                        cout<<"no\n";
                else cout<<"yes\n";

                v.clear();
        }

}
