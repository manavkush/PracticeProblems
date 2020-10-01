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
//This was a very nice question
//The key concept is that the total number of 1s are conserved in AND and OR (sum of both)
//So for each bit position, the sum of all the 1 in all the numbers will remain same after any number of operations
//So we just need to push the 1s towards the biggest number

int main()
{
    FIO;
    lli n;
    cin>>n;
    lli a[n];
    re(i,n)
    {
        cin>>a[i];
    }
    vector<lli> b(n);
    for(int bit=0;bit<23;bit++)
    {
        int count=0;
        re(i,n)
        {
            count+=(a[i]>>bit)&1;
        }
        re(i,count)
        {
            b[i]=(b[i])|(1<<bit);
        }
    }
    lli ans =0;
    re(i,n)
    {
        ans+=b[i]*b[i];
    }
    cout<<ans<<endl;


}