#include <bits/stdc++.h>
using namespace std;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define re(i,n)        for(int i=0;i<(n);i++)

int main()
{
    FASTIO;
    int k,q,i,j;
    cin>>k;

    int arr[k];
    re(i,k)
        cin>>arr[i];
    cin>>q;
    //=================================================
    stack<int> s;
    vector <int> v;
    re(i,k)
    {
        if(s.empty())
        {
                s.push(i);
                v.push_back(-1);
        }
        else
        {
            while(  arr[i]>arr[ s.top() ]  )
            {
                j=s.top();
                v[j]=i;
                s.pop();
                if(s.empty())
                    break;
            }
        s.push(i);
        v.push_back(-1);
        }
    }
    //========================================

    int l,r,count;
    while(q--)
    {
        cin>>l>>r;
        count=1;
        for(i=l;i<=r;)
        {
            if(v[i]==-1)
                break;
            else
            {
                if(v[i]<=r)
                {
                count++;
                i=v[i];
                }
                else    break;
            }
        }
        cout<<count<<"\n";
    }

}
