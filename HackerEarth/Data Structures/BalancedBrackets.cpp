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
        string str;
        stack<char> s;
        char ch;
        while(n--)
        {
                int flag=1,i;
                int t;
                cin>>t;
                
                cin>>str;
                if(str.size()%2)
                {
                        cout<<"NO\n";
                        continue;
                }
                for(i=0;i<str.size();i++)
                {
                        ch=str[i];
                        if(ch=='('||ch=='['||ch=='{')
                                s.push(ch);
                        else
                        {
                                if(s.empty())
                                {
                                        cout<<"NO\n";
                                        flag=0;
                                        break;
                                }
                                else if ((ch==')'&&s.top()=='(')||(ch=='}'&&s.top()=='{')||(ch==']'&&s.top()=='['))
                                {
                                        s.pop();
                                }
                                else
                                {
                                        cout<<"NO\n";
                                        flag=0;
                                        break;
                                }
                        }

                }
                if(flag)
                        cout<<"YES\n";
                else
                {
                        while(!s.empty())
                                s.pop();
                }
        }

}
