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
    int n,k;
    cin>>n>>k;
    int a[n];
    int sum=0;
    re(i,n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int max=0;
    
    re(i,k)
    {
        int temp=sum;
        int j=i;
        while(j<n)
        {
            temp=temp-a[j];
            j=j+k;
        }
        if(abs(temp)>max)
            max=abs(temp);
    }
    cout<<max;
}   
