#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

// I saw the solution for this program. This is a greedy based problem

int main()
{
    FIO;
    string s,ans;
    cin>>s;
    int n=s.size();
    re(i,n)
    {
        int sz=ans.size();
        bool flag=0;
        if(sz>1&&(ans[sz-1]==ans[sz-2])&&ans[sz-1]==s[i])
            flag=1;
        if(sz>2&&(ans[sz-1]==s[i])&&(ans[sz-2]==ans[sz-3]))
            flag=1;
        if(!flag)
            ans+=s[i];
    }
    cout<<ans;
}