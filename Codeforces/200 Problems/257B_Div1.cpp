#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define re(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
const int N = 1e5+5;
const long long MAXVAL=1e12;
vector<pair<int,int>> *adj;
long long *dist;
int *cnt;
int v,e,k;

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


void dijsktra()
{

    re(i,v)
    {
        dist[i+1]=MAXVAL;
    }
    dist[1]=0;

    set<pair<int,int>>s;
    s.insert(mp(0,1));
    
    // unordered_map<int,int>parent;
    // parent[1]=-1;

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
                
                // parent[destId] = id;
                auto f = s.find(mp(dist[destId],destId));
                if(f!=s.end())
                {
                    s.erase(f);
                }
                long long targVal = dist[id] + destVal;
                dist[destId] = targVal;
                s.insert(mp(targVal,destId));
                cnt[destId]=1;
            }
            else if(dist[destId]==dist[id]+destVal)
            {
                cnt[destId]++;
            }

        }
    }
    if(dist[v]==MAXVAL)
    {
        cout<<-1<<endl;
        return;
    }
    //backtracing(parent);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>v>>e>>k;
    adj = new vector<pair<int,int>>[v+1];           // Adjacency list
    dist = new long long [v+1];                     // Distance array
    cnt = new int [v+1];                            // Count array to keep count of the number of shortest paths
    re(i,v+1)
    {
        cnt[i]=0;
        dist[i]=0;
    }
    pair<int,int> railstations [k];
    int x,y,w;
    re(i,e)
    {
        cin>>x>>y>>w;
        addEdge(x,y,w);
    }
    re(i,k)
    {
        int s,w;
        cin>>s>>w;
        railstations[i]=mp(s,w);
        addEdge(1,s,w);
    }
    dijsktra();
    int stationcount=0;
    re(i,k)
    {
        if(dist[railstations[i].ff]==railstations[i].ss)
        {
            if(cnt[railstations[i].ff]>1)
            {
                cnt[railstations[i].ff]--;
                stationcount++;
                continue;
            }
            else
            {
                cnt[railstations[i].ff]--;
            }
        }
        else
        {
            stationcount++;
        }
        
    }
    cout<<stationcount;
}
