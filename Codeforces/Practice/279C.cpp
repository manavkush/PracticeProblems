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

int main()
{
    FIO;
    string str;
    cin>>str;
    string temp,ans;
    ans="";
    vi vec;
    int a,b;
    cin>>a>>b;
    int n=str.size();
    int prev=int(str[0]);
    for(int i=0;i<n-1;i++)
    {
        ans=ans+str[i];
        int num=stoi(ans);
        if(num%a!=0)
        {
            ans=to_string(num%a);
        }
        else
        {
            vec.push_back(i);
            ans="";
        }
        
    }
}