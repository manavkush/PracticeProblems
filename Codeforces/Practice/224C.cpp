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
    int a[n];
    re(i,n)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<-1;
        return 0;
    }
    sort(a,a+n);
    if(n==2)
    {
        int d=a[1]-a[0];
        if(d==0)
        {
            cout<<1<<endl;
            cout<<a[0];
            return 0;
        }
        if(d%2)
        {
            cout<<2<<endl;
            cout<<a[0]-d<<" "<<a[1]+d;
            return 0;
        }
        else
        {
            cout<<3<<endl;
            cout<<a[0]-d<<" "<<(a[1]+a[0])/2<<" "<<a[1]+d;
            return 0;
        }
    }
    else
    {
        map<int,int> s;
        for(int i=0;i<n-1;i++)
        {
            s[(a[i+1]-a[i])]++;
        }
        if(s.size()>2)  
        {
            cout<<0;
            return 0;
        }
        if(s.size()==1)
        {
            if(a[0]==a[1])
            {
                cout<<1<<endl;
                cout<<a[0];
                return 0;
            }
            int d=a[1]-a[0];
            cout<<2<<endl;
            cout<<a[0]-d<<" "<<a[n-1]+d;
            return 0;
        }
        else
        {
            auto itr=s.begin();
            itr++;
            if(itr->second>1)
            {
                cout<<0;
                return 0;
            }
            if(itr->first!=2*(s.begin()->first))
            {
                cout<<0;
                return 0;
            }
            else
            {
                cout<<1<<endl;
                for(int i=0;i<n-1;i++)
                {
                    if(a[i+1]-a[i]==(s.begin()->first))
                        continue;
                    else 
                    {
                        cout<<(a[i+1]+a[i])/2;
                        break;
                    }
                }
            }
            
        }
        
    }
    
    
    
}