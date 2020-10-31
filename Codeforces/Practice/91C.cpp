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
const int N=1e5+10;
int a[N];

int main()
{
    FIO;
    int t;
    cin>>t;
    multiset<int,greater<int> > s;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int count=0;
        re(i,n)
        {
            cin>>a[i];
            if(a[i]>=x)
                count++;
            else s.insert(a[i]);
        }
        auto itr=s.begin();
        while ((!s.empty())&&(itr!=s.end()))
        {
            int cnt=1;
            while ((itr!=s.end()))
            {
                
                if(cnt*(*itr)>=x)
                {
                    //deb(*itr);
                    count++;
                    itr++;
                    break;
                }
                else
                {
                    //deb(*itr);
                    cnt++;
                    itr++;
                }
            }
        }
        cout<<count<<endl;
        s.clear();

    }
}