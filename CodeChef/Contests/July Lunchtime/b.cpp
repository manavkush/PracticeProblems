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
    while(t--)
    {
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        int s[n][m];
        int a,b;
        if(2*x<=y)
        {
             a=x;
             b=x;
        }
        else if(y>=x)
        {
            a=y-x;
            b=x;            
        }
        else
        {
            a=0;
            b=y;
        }
        if(n==1&&m==1)
        {
            cout<<x<<endl;
            continue;
        }

        re(i,n)
        {
            re(j,m)
            {
                if((i+j)%2==0)
                    s[i][j]=b;
                else
                    s[i][j]=a; 
            }
        }
        lli sum=0;
        re(i,n)
        {
            re(j,m)
            {
                sum+=s[i][j];
            }
        }
        cout<<sum<<endl;
    }
}