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
        int n;
        cin>>n;
        int a[n];
        int count=0;
        vi v;
        re(i,n)
        {
            cin>>a[i];
            if(a[i]==1)
            {
                count++;
                v.push_back(i);
            }
        }
        int max=0;
        if(n==1)        //Only 1 number
        {
            cout<<"First\n";
            continue;
        }
        if(count==0)        //No ones
        {
            cout<<"First\n";
            continue;
        }
        if(count==n) //------------------       //All onnes
        {
            if(n%2)
            {
                cout<<"First\n";
                continue;
            }
            else
            {
                cout<<"Second\n";
                continue;
            }
        }//-------------------------------
        if(a[0]!=1)
        {
            cout<<"First\n";
        }
        else
        {
            int flag=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]==1)
                flag++;
                else break;
            }
            if(flag%2)
            {
                cout<<"Second\n";
            }
            else cout<<"First\n";
        }

    }
}