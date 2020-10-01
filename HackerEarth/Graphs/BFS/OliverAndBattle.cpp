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

int temptropes=0;
int maxtropes=0;
int troops=0;
const int N=1e3+1;
vector<pair<int,int> > ones;
int n,m;
int adj[N][N];
bool vis[N][N];
int dr[]={1,-1,0,0,1,-1,-1,1};
int dc[]={0,0,1,-1,1,1,-1,-1};
queue<int> qr,qc;

//=============================INITIALIZING========================
void init()
{
    re(i,N)
    {
        re(j,N)
        {
            vis[i][j]=false;
            adj[i][j]=0;
        }
    }
}
//==============================INITIALIZING========================
void explore(int row,int col)
{
    re(i,8)
    {
        int rr=row+dr[i];
        int cc=col+dc[i];
        if(rr<0||rr>=n)
            continue;
        if(cc<0||cc>=m)
            continue;
        if(vis[rr][cc])
            continue;
        if(adj[rr][cc]==0)
            continue;
        qr.push(rr);
        qc.push(cc);
        vis[rr][cc]=true;
    }
}

void bfs()
{
    maxtropes=0;        //Calculating the maximum soldiers in a troop
    troops=0;           // Calculating the number of troops of soldiers

    for(auto x:ones)
    {
        int sx=x.first;
        int sy=x.second;
        if(vis[sx][sy])
            continue;
        temptropes=0;       //Calculating soldiers in a troop
        qr.push(sx);    qc.push(sy);
        vis[sx][sy]=true;   
        while (!qr.empty())
        {
            int row=qr.front();
            int col=qc.front();
            qr.pop(); qc.pop();
            temptropes++;
            explore(row,col);
        }
        if(temptropes>maxtropes)
            maxtropes=temptropes;
        troops++;
        //cout<<sx<<" "<<sy<<endl;
    }
    cout<<troops<<" "<<maxtropes<<endl;
}

int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        init();
        cin>>n>>m;
        re(i,n)     //Entering the matrix
        {
            re(j,m)
            {
                cin>>adj[i][j];
                if(adj[i][j]==1)
                    ones.pb(mp(i,j));       //Making the array of all the ones
            }
        }
        //cout<<ones.size()<<endl;
        bfs();
        ones.clear();
    }
    
}