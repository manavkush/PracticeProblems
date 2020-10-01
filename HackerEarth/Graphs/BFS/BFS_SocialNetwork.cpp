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

vector<int> *adj ;
bool *vis;

int bfs(int s,int t)
{
    int count=0;
    int currlayer=1;
    int nextlayer=0;
    int movecount=0;
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        currlayer--;
        if(movecount==t)
        {
            count++;
        }
        else if(movecount>t)
            return count;
        for(auto x:adj[top])
        {
            if(!vis[x])
            {
                q.push(x);
                vis[x]=true;
                nextlayer++;
            }
        }
        if(currlayer==0)
        {
            currlayer=nextlayer;
            nextlayer=0;
            movecount++;
        }

    }
    return count;
}

int main()
{
    FIO;
    int n,e;
    cin>>n>>e;
    adj =new vector<int> [n+1];

    re(i,e)
    {
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    // re(i,n+1)
    //     {
    //         cout<<i<<": ";
    //         for(auto x:adj[i])
    //             cout<<x<<" ";
    //         cout<<endl;
    //     }
    int m;
    cin>>m;
    re(i,m)
    {
        vis = new bool [n+1] ;
        re(i,n+1)
            vis[i]=false;
        cout<<endl;       
        int s,t;
        cin>>s>>t;
        cout<<bfs(s,t)<<endl;
        delete vis;
    }


}