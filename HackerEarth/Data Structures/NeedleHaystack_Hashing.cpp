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
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    int t;
	cin>>t;
	while(t--)
	{
		string pat,text;
		cin>>pat>>text;
        int flag=0;
		unordered_map <char,int> m;
        re(i,text.size())
        {
            m[text[i]]++;
        }
        tr(itr,m)
            cout<< itr->first <<" "<< itr->second <<endl;
        re(i,pat.size())
        {
            if(m.find(pat[i])==m.end())
            {
                flag=1;
                break;
            }
            else if(m[pat[i]]<=0)
            {
                flag=1;
                break;
            }
            else m[pat[i]]--;
        }
        
        if(flag)
        cout<<"NO\n";
        else cout<<"YES\n";
	}
}