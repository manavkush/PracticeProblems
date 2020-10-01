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
#define re(i,n)        for(long long int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    lli t,s;
    string str;
    map<char,lli> mp;
    cin>>t;
    while(t--)
    {
        lli n, q;

        cin>>n>> q;
        cin>>str;
        re(i,n)
            mp[str[i]]++;
        lli count=0;
        re(i,q)
        {
            count=0;
            cin>>s;
            for(auto itr=mp.begin();itr!=mp.end();itr++)
            {
                if((itr->second)>s)
                    count+=(itr->second)-s;
            }
            cout<<count<<endl;
        }
        mp.clear();
    }

}
