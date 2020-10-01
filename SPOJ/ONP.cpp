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
int priority(char s)
        {
                if(s=='(')
                        return 1;
                else if(s=='^')
                        return 6;
                else if(s=='/')
                        return 5;
                else if(s=='*')
                        return 4;
                else if(s=='-')
                        return 3;
                else if(s=='+')
                        return 2;
        }

int main()
{
        FASTIO;
        int t,n;
        cin>>t;
        stack<char> s;


        while(t--)
        {
                string str;
                cin>>str;
                string ot;
                while(!s.empty())
                        s.pop();
                re(i,str.size())
                {
                        if(str[i]=='(')
                                s.push('(');
                        else if((str[i]>=65&&str[i]<=90)||(str[i]>=97&&str[i]<=122))
                                ot+=str[i];
                        else if(str[i]==')')
                                {
                                        while(s.top()!='(')
                                        {
                                                ot+=s.top();
                                                s.pop();
                                        }
                                        s.pop();
                                }
                        else
                        {
                                while(priority(str[i])<priority(s.top()))
                                {
                                        ot+=s.top();
                                        s.pop();
                                        if(s.empty())
                                                break;
                                }
                                s.push(str[i]);
                        }
                }
                cout<<ot<<endl;
        }
}
