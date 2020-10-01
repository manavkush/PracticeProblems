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

const lli num=1e9+7;
int main()
{
    FIO;
    int n,l,r;
    cin>>n>>l>>r;
    int count=0;
    string s(n,'l');
    
    int l1=3*(ceil(n/3));
    for(int i=l1;i<=r;i=i+3)
    {
        count+=i;
        count=count%num;
    }
    cout<<count;

}