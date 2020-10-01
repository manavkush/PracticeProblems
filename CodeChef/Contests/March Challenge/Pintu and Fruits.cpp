#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int t,temp,i,j,n,m;
    cin>>t;
    while(t)
    {
        cin>>n>>m;
        int cost[m]={-1};
        vector<int>vec1,vec2;

        for(i=0;i<n;i++)
        {
            cin>>temp;
            vec1.push_back(temp);
        }

        for(i=0;i<n;i++)
        {
            cin>>temp;
            vec2.push_back(temp);
        }
        for(i=1;i<=m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(vec1[j]==i)
                    cost[i-1]=cost[i-1]+vec2[j];
            }
        }
        int lowcost=cost[0];
        for(i=0;i<m;i++)
        {
            if(cost[i]<lowcost&&cost[i]>=0)
                lowcost=cost[i];
                cout<<cost[i]<<" ";
        }
        cout<<lowcost<<endl;
        t--;
    }
}
