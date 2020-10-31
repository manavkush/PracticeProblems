#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vlli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"
#define pb push_back
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
///                     Another Concept was that (A*B)%C=((A%C)*(A%C))%C
///                     We make blocks of a which are continuous
///                     These blocks when added and multiplied will give the req. number +1
int main()
{
    FASTIO;
    lli i,count=0,sum=0;
    string str;
    cin>>str;
    lli cnt=1;
    vlli a;
    for(i=0;i<str.size();i++)
    {
        if(str[i]=='a')
        {
            count++;
            sum++;
        }
        else if(str[i]=='b')
        {
            if(count)
                a.push_back(count);
            count=0;
        }
    }
    if(count)
        a.push_back(count);
    cnt=1;
    for(i=0;i<a.size();i++)
    {
        cnt*=a[i]+1;
        cnt%=1000000007;
    }
    cout<<(cnt-1)%1000000007;


}
