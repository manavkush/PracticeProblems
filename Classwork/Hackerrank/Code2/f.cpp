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
    int n,m,i;
    cin>>n>>m;
    //=================================================
    int arr[n];
    stack<int> s;
    vector <int> v,v2;
    re(i,n)
    {
        if(s.empty())
        {
                s.push(i);
                v.push_back(-1);
        }
        else
        {
            while(  arr[i]>arr[ s.top() ]  )
            {
                j=s.top();
                v[j]=i;
                s.pop();
                if(s.empty())
                    break;
            }
        s.push(i);
        v.push_back(-1);
        }
    }
    //========================================
    
    
}