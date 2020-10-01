//------------------THIS IS NOT THE CORRECT SOLUTION OF THE QUESTION----------------------

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

// ----------------------DEBUG TEMPLATE--------------------------
void __print(int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// ----------------------DEBUG TEMPLATE--------------------------

int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
int n,m;

vector<char> *mat;
vector<int> *vis;
int x,y;
queue<int> qr,qc;
int movecount=0;
int currlayer=1;
int nextlayer=0;
//=============================INITIALIZING========================
void init()
{
    re(i,n)
    {
        re(j,m)
        {
            vis[i][j]=-1;
        }
    }
}
//===========================COMPARATOR============================
bool comp(const pair<int,int> &a, const pair<int,int> &b)
{
    int v1=vis[a.first][a.second];  int v2=vis[b.first][b.second];

    return (v1>v2);
}
//==========================
void explore(int row, int col)
{
    vector<pair<int,int> > p;
    re(i,4)
    {
        int rr=row+dr[i];
        int cc=col+dc[i];
        if(rr>=n||rr<0) continue;
        if(cc>=m||cc<0) continue;
        if(mat[rr][cc]=='*') continue;
  
        if(vis[rr][cc]==-1)
        {
            vis[rr][cc]=vis[row][col]+int(mat[rr][cc])-int('0');
            // cout<<rr<<" "<<cc<<" ";
            // deb(vis[rr][cc]);
            p.push_back(mp(rr,cc));
            nextlayer++;          
        }
    }
    sort(p.begin(),p.end(),comp);
    //__print(p);
    for(auto x:p)
    {
        qr.push(x.first);
        qc.push(x.second);
    }
}
//===============================BFS FUNCTION========================

void bfs(int xi,int yi)
{
    FIO;
    movecount=0;
    currlayer=1;
    nextlayer=0;

    qr.push(x); qc.push(y);
    vis[x][y]=int(mat[x][y]-'0');
    while(!qr.empty())
    {
        int row=qr.front();     int col=qc.front();
        qr.pop();   qc.pop();
        currlayer--;
        if((row==xi)&&(col==yi))
        {
            cout<<movecount<<" "<<vis[row][col]<<endl;
            while (!qr.empty())
            {
                qr.pop();
                qc.pop();
            }
            return;
        }
        explore(row,col);
        if(currlayer==0)
        {
            currlayer=nextlayer;
            nextlayer=0;
            movecount++;
        }
    }
    cout<<"-1 -1\n";

}
//=============================MAIN FUNCTION ================================
int main()
{   FIO;
    cin>>n>>m;
    mat=new vector<char> [n];
    vis=new vector<int> [n];
    re(i,n)
    {
        re(j,m)
        {
            char temp;
            cin>>temp;
            mat[i].push_back(temp);
            vis[i].push_back(-1);
        }
    }
    cin>>x>>y;  x--; y--;
    int t;
    cin>>t;
    while(t--)
    {
        init();
    
        int xi,yi;
        cin>>xi>>yi;
        xi--; yi--;
        if(mat[xi][yi]=='*')
        {
            cout<<"-1 -1"<<endl;
        }
        else
        {
            //deb(y);  
            bfs(xi,yi);
            //cout<<"Else\n";
        }
    }
}