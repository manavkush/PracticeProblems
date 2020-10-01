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
const int N=1e9;
int main()
{
    FIO;
    int t;
    cin>>t;
    map<int,int> a;
    while(t--)
    {
        lli n,k;
        cin>>n>>k;
        lli rem;

        lli x=0;
        lli count=0;
        re(i,n)
        {
            lli temp;
            cin>>temp;
            rem=k-temp%k;
            if(rem==k)
                rem=0;
            a[rem]++;
        }
        int max=0;
        lli id=0;
        
        for(auto i=a.begin();i!=a.end();i++)
        {
            if(i->first==0)
                continue;
            if(i->second>=max)
            {
                max=i->second;
                id=i->first+1;
            }
        }
        if(!max)
        {
            cout<<0<<endl;
            continue;
        }        
        cout<<(max-1)*k+id<<endl;
        a.clear();
    }
}