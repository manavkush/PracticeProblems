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
    int n;
    cin>>n;
    int count=0;
    for(int i=2;i<=n;i++)
    {
        int num=i;
        map<int,int> m;
        while(num%2==0)
        {
            num=num/2;
            m[2]++;
        }
        for(int j=3;j<=num;j=j+2)
        {
            while(num%j==0)
            {
                num=num/j;
                m[j]++;
            }
        }
        if(num!=1)
        m[num]++;

        if(m.size()==2)
            count++;
        m.clear();
    }
    cout<<count;
}