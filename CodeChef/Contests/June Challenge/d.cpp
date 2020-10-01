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
lli  lb(lli  n)
{
    lli count=0;
    while(n%2==0)
    {
        count++;
        n=n/2;
    }
    return count+1;
}

int main()
{
    FASTIO;
    int t;
    cin>>t;
    while(t--)
    {
        lli  count=0;
        lli  ts;
        cin>>ts;
        lli lsb = lb(ts);
        uint64_t l=lsb;
        count=ts/(1<<l);
        cout<< count<< endl;        

    }  
}