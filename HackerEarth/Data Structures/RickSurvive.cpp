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
        int n;
        cin>>n;
        int arr[n];
        re(i,n)
            cin>>arr[i];
        sort(arr,arr+n);
        re(i,n)
        {
            arr[i]=(arr[i]-i+i/6);
        }
        int flag=0;
        re(i,n)
        {
            if(arr[i]<=0)
            {
                cout<<"Goodbye Rick\n"<<i<<endl;
                flag=1;
                break;
            }  
        }
        if(!flag)
            cout<<"Rick now go and save Carl and Judas"<<endl;
    }  
}