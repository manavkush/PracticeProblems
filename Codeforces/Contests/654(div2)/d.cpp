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

int a[300][300];
void print(int n)
{
    re(i,n)
    {
        re(j,n)
            cout<<a[i][j]<<"";
        cout<<endl;
    }
}
int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        re(i,n)
            re(j,n)
                a[i][j]=0;
        // if(k==0)
        // {
        //     cout<<0<<endl;
        //     print(n);
        //     continue;
        // }
        if(k%n==0)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<2<<endl;
        }
        int x=k/n;
        int y=k%n;
        // deb(x); deb(y);
        re(i,n)
        {
            for(int j=0;j<x;j++)
            {
                a[i][(i+j)%n]=1;
            }
        }
        // re(i,n)
        // {
        //     re(j,n)
        //     {
        //         cout<<a[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        for(int i=0;i<n&&y>0;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][(i+j)%n]==0)
                {
                    a[i][(j+i)%n]=1;
                    y--;
                    break;
                }
            }
        }
        print(n);       
        
    }
}