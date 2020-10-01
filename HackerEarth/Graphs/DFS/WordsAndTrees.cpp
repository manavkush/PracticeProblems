/*
This question was a very good question and showed the power of dfs algorithm

                       The question is:

You are given a rooted tree with N nodes. Each node contains a lowercase English letter. Node with label 1 is the root.There are Q questions of the form

X S: Here X is the root of subtree and S is a string.

For each question, let T be the string built using all the characters in the nodes of subtree with root X (each subtree node character comes exactly once) .
For each question, print minimum number of characters to be added to T , so that the we can build S using some characters of string T (each character of string T can be used at most once).


Hint: Find all the characters coming in each subtree and use it to get the answer to each question.
*/

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
//=======================================GRAPH CLASS=========================================
int V;
vector<int>*adj;
int mat[100005][26];
vector<char> alp(100005);
vector<bool> vis(100005);

void dfs(int s)
{
    vis[s]=1;
    for(auto x: adj[s])
    {
        if(vis[x])
            continue;
        vis[x]=1;
        dfs(x);
        re(i,26)
        {
            mat[s][i]+=mat[x][i];
        }
    }
    mat[s][alp[s]-'a']++; 
}
//==========================================GRAPH CLASS=====================================
int main()
{
    FIO;
    int n,q;
    cin>>n>>q;
    adj = new vector<int> [n+1];
    
    re(i,n)
    {
        cin>>alp[i+1];
    }
    re(i,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    // re1(i,1,7)
    // {
    //     cout<<"Node "<<i<<": \n";
    //     re(j,26)
    //     {
    //         if(mat[i][j])
    //         {
    //             cout<<char('a'+j)<<" "<<mat[i][j]<<endl;
    //         }
    //     }
    // }
    re(i,q)
    {
        int node;
        string s;
        cin>>node>>s;
        vi inp(26);
        re(i,s.size())
        {
            inp[s[i]-'a']++;
        }
        lli ans=0;
        re(i,26)
        {
            // if(max(0,inp[i]-mat[node][i]))
            //     cout<<char('a'+i)<<" "<<(max(0,inp[i]-mat[node][i]))<<endl;
            ans+=max(0,inp[i]-mat[node][i]);
        }
        cout<<ans<<endl;
    }

}