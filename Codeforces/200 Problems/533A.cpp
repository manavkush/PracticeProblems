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
    int n;
    cin>>n;
    int a[n];
    lli sum=0;
    re(i,n)
    {
        cin>>a[i];
    }
                lli min=1000000;
                int minid=1;
    re(i,1000)
    {
        sum=0;
        int t=i+1;
        re(j,n)
        {
            int temp;
            temp=abs(a[j]-t);
            if(temp<=1)
                continue;
            else sum+=temp-1;
        }
        
        if(sum<min)
        {
            min=sum;
            minid=t;
        }
    }
    cout<<minid<<" "<<min;
}