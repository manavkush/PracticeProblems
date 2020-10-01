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
    vector<pair<int,int> > v;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n][m];
        re(i,n)
        {
            re(j,m)
            {
                cin>>a[i][j];
            }
        }
        int flag=0;
        re(i,n)
        {
            re(j,m)
            {
                //first or last line
                if(i==0||i==n-1)
                {
                    if(j==0||j==m-1)        //corners
                    {
                        if(a[i][j]>2)
                        {
                            flag=1; break;
                        }
                        else 
                            a[i][j]=2;
                        continue;
                    }
                    if(a[i][j]>3)           // edges
                    {
                        flag=1;
                        break;
                    }
                    else
                        a[i][j]=3;
                        continue;
                }
                //first column or last column
                else if(j==0||j==m-1)
                {
                    if(a[i][j]>3)
                    {
                        flag=1;
                        break;
                    }
                    else a[i][j]=3;
                }
                else
                {
                    if(a[i][j]>4)
                    {
                        flag=1;
                        break;
                    }
                    else a[i][j]=4;
                }    
            }
        }
        if(flag)
        {
            cout<<"NO\n";
            continue;
        }
        else
        {
            cout<<"YES\n";
            re(i,n)
            {
                re(j,m)
                {
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        
    }
}