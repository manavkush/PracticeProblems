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
        
        int n0,n1,n2;
        cin>>n0>>n1>>n2;
        
        if(n0)
        {
            re(i,n0+1)
            {
                cout<<0;
            }
        }
        if(n2)
        {
            re(i,n2+1)
            {
                cout<<1;
            }
        }
        if(n1)
        {
            if(n0&&n2)
            {
                re(i,n1-1)
                {
                    cout<<(i&1);
                }
            }
            else if(n0)
            {
                re(i,n1)
                {
                    cout<<(!(i&1));
                }
            }
            else if(n2)
            {
                re(i,n1)
                {
                    cout<<(i&1);
                }
            }
            else
            {
                re(i,n1+1)
                {
                    cout<<(i&1);
                }
            }
            
        }
        cout<<endl;
        
    }
    
    
}