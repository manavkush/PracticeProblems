#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
vector<int> adj[N];
int visited[N]={0};


void addedge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs(int s,int k)
{
    if(visited[s])
        return;
    visited[s]=k;
    for(auto x:adj[s])
        dfs(x,k);
}

int main()
{
	int n,m,q;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
	
		addedge(a,b);
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int a,b;
		cin>>a>>b;
		int flag=0;
		for(auto x:adj[a])
		{
			if(x==b)
			{	flag=1;
				break;
			}
		}
		if(flag)	cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
}