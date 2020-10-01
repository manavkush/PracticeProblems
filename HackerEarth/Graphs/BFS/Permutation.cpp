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
int n;
string str;
string key;
string temp;
unordered_map<string,bool> vis;

int bfs()
{
    int movecount=0;
    int currlayer=1;
    int nextlayer=0;
    queue<string> q;
    q.push(str);
    while(!q.empty())
    {
        string top=q.front();
        q.pop();
        currlayer--;
        if(top==key)
        {
            return movecount;
        }
        
        for(int i=2;i<=n;i++)
        {
            temp=top;
            reverse(temp.begin(),temp.begin()+i);
            if(vis.find(temp)==vis.end())
            {
                vis[temp]=true;
                nextlayer++;
                q.push(temp);
            }
        }
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
    cin>>n;
    char c;
    re(i,n)
    {
        cin>>c;
        str+=c;
    }
    key=str;
    sort(key.begin(),key.end());
    cout<<bfs();
}