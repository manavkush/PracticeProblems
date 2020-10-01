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
    int t;
    cin>>t;
    while (t--)
    {
        string str;
        cin>>str;
        lli n=str.size();
        lli curr=0;
        lli res=0;
        for(lli i=0;i<n;i++)
        {
            if(str[i]=='+')
                curr++;
            
            else if(str[i]=='-')
            {
                curr--;
                if(curr<0)
                {
                    res+=i+1;
                    curr=0;
                } 
            }            
        }
        res+=n;
        cout<<res<<endl;
    }
    
}