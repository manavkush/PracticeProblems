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
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int ones=0;
        int a[n];       //int w[k];
        lli sum=0;
        vector<int> v;
        int temp;
        re(i,n) 
            cin>>a[i];
        re(i,k)
        {
            cin>>temp;
            if(temp==1)
                ones++;
            else v.push_back(temp);
        }
        sort(a,a+n);
        sort(v.begin(),v.end(),greater<int>());
        
        int end=n-1;
        int front=0;

        re(i,ones)
        {
            sum+=2*a[end];
            end--;
        }        
        for(auto x=0;x<v.size();x++)
        {
            sum+=a[front];
            sum+=a[end];
            front+=v[x]-1; 
            end--;           
        }
        
        
        cout<<sum<<endl;

    }
}