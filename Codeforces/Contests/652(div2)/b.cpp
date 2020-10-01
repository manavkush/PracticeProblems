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
// After seeing the solution. Couldn't do in the contest
int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s,str;
        cin>>s;
 
        int c2=0;
        int start=-1;
        int end=n;
        re(i,n)
        {
            if(s[i]=='1')
            {
                start=i;
                break;
            }
            else
            str+='0';
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                end=i;
                break;
            }
        }

        if(start==-1||end==n)   
        {
            cout<<s<<endl;
            continue;
        }
        if(start==end+1)
        {
            cout<<s<<endl;
            continue;
        }
        
        str+='0';
        re(i,n-1-end)
        {
            str+='1';
        }
        cout<<str<<endl;        
    }
}