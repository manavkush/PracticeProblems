#include<bits/stdc++.h>
using namespace std;
#define mod 100000
int val[100001];
 
void init()
{
	for(int i=1;i<=100000;i++)
	{
		val[i]=-1;
	}
}
int BFS(int n,int a[],int key,int tar)
{
	queue<int> q;
	val[key]=0;
	q.push(key);
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		
		for(int i=0;i<n;i++)
		{
			int child=(1LL*curr*a[i])%mod;
			
			if(val[child]==-1)
			{
				val[child]=1+val[curr];
				
				q.push(child);
			}
		}
	}
	return val[tar];
}
int main()
{
	int key,tar;
	cin>>key>>tar;
	
	int n;
	cin>>n;
	
	int a[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	init();
	
	cout<<BFS(n,a,key,tar);
	
}