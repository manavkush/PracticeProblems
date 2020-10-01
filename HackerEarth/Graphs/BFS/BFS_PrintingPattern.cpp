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
const int N=1e3+1;
int adj[N][N];
bool vis[N][N];
int dr[]={1,-1,0,0,1,-1,-1,1};
int dc[]={0,0,1,-1,1,1,-1,-1};
queue<int> qr,qc;
int movecount=0;
int currlayer=1;
int nextlayer=0;
void explore(int row,int col)
{
    re(i,8)
    {
        int rr=row+dr[i];
        int cc=col+dc[i];
        if(rr<0||rr>=N)
            continue;
        if(cc<0||cc>=N)
            continue;
        if(vis[rr][cc])
            continue;
        qr.push(rr);
        qc.push(cc);
        nextlayer++;
        vis[rr][cc]=true;
    }
}

void bfs( int sx, int sy)
{
    
    qr.push(sx);    qc.push(sy);
    vis[sx][sy]=true;
    adj[sx][sy]=0;
    while (!qr.empty())
    {
        int row=qr.front();
        int col=qc.front();
        qr.pop(); qc.pop();
        adj[row][col]=movecount;
        currlayer--;
        explore(row,col);
        if(currlayer==0)
        {
            currlayer=nextlayer;
            nextlayer=0;
            movecount++;
        }
    }  
}

int main()
{
    FIO;
    int r,c,sx,sy;
    cin>>r>>c>>sx>>sy;
    bfs(sx,sy);
    re(i,r)
    {
        re(j,c)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}