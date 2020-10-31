#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define re(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
const long long MAXVAL=1e12;
vector<pair<int,int>> *adj;
int v,e;

void addEdge(int x, int y, int val)
{
    adj[x].push_back(mp(y, val));
    adj[y].push_back(mp(x, val));
}

// void backtracing(unordered_map<int,int>&parent)     // To make an array of the path
// {
//     vector<int>path;

//     for(int temp =v; temp !=-1 ; temp = parent[temp])
//     {
//         path.pb(temp);
//     }
//     reverse(all(path));

//     tr(it,path){
//         cout<<*it<<" ";
//     }
//     cout<<endl;
// }

void dijsktra(){
    long long dist[v+1];

    re(i,v)
    {
        dist[i+1]=MAXVAL;
    }
    dist[1]=0;

    set<pair<int,int>>s;
    s.insert(mp(0,1));
    
    unordered_map<int,int>parent;
    parent[1]=-1;

    while(!s.empty())
    {

        auto  p = *(s.begin());
        int id = p.ss;
        int val = p.ff;

        s.erase(s.begin());

        for(auto x : adj[id])
        {
            
            int destId = x.ff;
            int destVal = x.ss;

            if(dist[destId] >dist[id] + destVal)
            {
                
                parent[destId] = id;
                auto f = s.find(mp(dist[destId],destId));
                if(f!=s.end())
                {
                    s.erase(f);
                }
                long long targVal = dist[id] + destVal;
                dist[destId] = targVal;
                s.insert(mp(targVal,destId));
            }

        }
    }
    if(dist[v]==MAXVAL)
    {
        cout<<-1<<endl;
        return;
    }
    vector<int>path;
    delete adj;

    for(int temp =v; temp !=-1 ; temp = parent[temp])
    {
        path.pb(temp);
    }
    reverse(all(path));

    tr(it,path){
        cout<<*it<<" ";
    }
    cout<<endl;        
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>v>>e;
    adj = new vector<pair<int,int>>[v+1];
    int x,y,w;
    re(i,e)
    {
        cin>>x>>y>>w;
        addEdge(x,y,w);
    }

    dijsktra();
}
