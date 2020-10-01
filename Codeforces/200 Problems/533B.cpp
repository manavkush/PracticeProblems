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
    string str,s;
    cin>>str;
    map<char,int> mp;
    re(i,n)
    {
        int j=i+1;
        int flag=1;
        while(j<(i+k)&&j<n)
        {
            if(str[i]!=str[j])
            {
                flag=0;
                break;
            }
            j++;
        }
        if(j-i==k)
        {
            mp[str[i]]++;
        }
        i=j-1;
    }
    int max=0;
    for(auto x=mp.begin();x!=mp.end();x++)
    {
        if(x->second>max)
            max=x->second;
    }
    cout<<max;
}