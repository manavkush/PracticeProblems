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
const lli N=1000000007;
int main()
{
    FIO;
    int n,m;
    cin>>n>>m;
    set<char> s[m];
    string str;
    re(i,n)
    {
        cin>>str;
        re(j,m)
        {
            s[j].insert(str[j]);
        }
    }
    lli sum=1;
    re(i,m)
    {    
        sum*=s[i].size();
        sum=sum%N;
    }
    cout<<sum;
}