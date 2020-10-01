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
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FIO;
    int r,c;
    int a,b;
    cin>>r>>c>>a>>b;
    for(int i=1;i<=r*a;i++)
    {
        for(int j=1;j<=c*b;j++)
        {
            if(((i-1)/a+(j-1)/b)%2)
            {
                cout<<".";
            }
            else cout<<"X";

        }
        cout<<endl;
    }
}