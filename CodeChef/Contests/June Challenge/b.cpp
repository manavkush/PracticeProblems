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
    string str;

    while(t--)
    {
        cin>>str;
        int count=0;
        int n=str.size();
        re(i,n)
        {
            if((str[i]=='x'&&str[i+1]=='y')||(str[i]=='y'&&str[i+1]=='x'))
            {
                count++;
                i++;
            }
        }
        cout<<count<<endl;
    }
}