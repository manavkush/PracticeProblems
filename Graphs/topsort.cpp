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
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
const int N=1e5+10;
stack<int> st;
bool vis[N];
void topsort(vector<int>* adj,int n, int s)
{
    if(vis[s])
        return;
    vis[s]=true;
    for(auto x:adj[s])
    {
        if(vis[x])
            continue;
        else
        {
            topsort(adj,n,x);
        }
        
    }
    st.push(s);
}

int main()
{
    FIO;
    int m,n;
    cin>>m>>n;
    vector<int> *adj;
    adj=new vector<int> [n];
    re(i,m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    topsort(adj,n,0);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
    }
}