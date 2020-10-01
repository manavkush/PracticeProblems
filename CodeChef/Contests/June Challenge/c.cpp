#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n,temp;
        cin>>n;
        int a[3]={0};
        int flag=1;

        re(i,n)
        {
            cin>>temp;
            if(temp==5)
            {
                a[0]++;
            }
            else if(temp==10)
            {
                if(a[0]>0)
                {
                    a[0]--;
                    a[1]++;
                }
                else flag=0;
                
            }
            else if(temp==15)
            {
                if(a[1]>0)
                    a[1]--;
                else if(a[0]>1)
                    a[0]-=2;
                else 
                {
                    flag=0;
                }
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}