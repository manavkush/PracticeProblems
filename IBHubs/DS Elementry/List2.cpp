#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vlli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"
#define pb push_back
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

void sortedinsert(stack<int> &s ,int key)
{
        if(s.empty()||key>s.top())
        {
                s.push(key);
                return;
        }
        int top=s.top();
        s.pop();
        sortedinsert(s,key);
        s.push(top);
}
void sort(stack <int> &s)
{
        if(!s.empty())
        {
                int temp=s.top();
                s.pop();
                sort(s);
                sortedinsert(s,temp);
        }
        else
                return;
}


int main()
{
        FASTIO;
        int n,temp;
        cin>>n;
        stack <int> s;
        re(i,n)
        {
                cin>>temp;
                s.push(temp);
        }
        sort(s);
        while(!s.empty())
        {
                cout<<s.top()<<" ";
                s.pop();
        }
}
