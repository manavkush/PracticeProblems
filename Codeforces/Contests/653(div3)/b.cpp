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
        int n,n1;
        cin>>n;
        n1=n;
        int m[4]={0};
        while(n%2==0&&n>1)
        {
            m[2]++;
            n=n/2;
        }
        while(n%3==0&&n>1)
        {
            m[3]++;
            n=n/3;
        }
        if(n!=1)
        {
            cout<<-1<<endl;
            continue;
        }
        
        if(m[2]>m[3])
        {
            cout<<-1<<endl;
            continue;
        }
        int k=m[3]-m[2];
        cout<<(k+m[3])<<endl;

    }
}