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

string flip(string str,int k)
{
    string temp;
    re(i,k)
    {
        if(str[i]=='1')
            temp+='0';
        else    temp+='1';
    }
    reverse(temp.begin(),temp.end());
    return (temp+str.substr(k));
}

int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        if(a==b)
        {
            cout<<0<<endl;
            continue;
        }
        vi v;
        int i=n-1;

        while(a!=b)
        {
            if(a[i]==b[i])
            {
                i--;
                continue;
            }
            if(a[i]==a[0])
            {
                a=flip(a,i+1);
                v.pb(i+1);
                i--;
                continue;
            }
            else
            {
                a=flip(a,1);
                v.pb(1);
                a=flip(a,i+1);
                v.pb(i+1);
                i--;
                continue;
            }           
        }
        cout<<v.size()<<" ";
        for(auto x:v)
            cout<<x<<" ";
        cout<<endl;
    }
}