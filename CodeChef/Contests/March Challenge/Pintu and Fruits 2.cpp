#include<iostream>
#include<vector>


class bask
{
public:
    int sno;
    int cost;
};



using namespace std;
int main()
{
    int t,i,j,n,m,low,flag;
    int total[50];
    cin>>t;
    while(t)
    {

        cin>>n>>m;
        for(i=0;i<m;i++)
            total[i]=-1;
        bask basket[n];
        for(i=0;i<n;i++)
            cin>>basket[i].sno;
        for(i=0;i<n;i++)
            cin>>basket[i].cost;

        for(i=0;i<n;i++)
        {
            total[basket[i].sno-1]=0;
        }

        for(i=0;i<n;i++)
        {
            total[basket[i].sno-1] +=basket[i].cost;
        }

        for(i=0;i<m;i++)
        {
            if(total[i]!=-1)
                break;
        }
        low=total[i];
        for(;i<m;i++)
        {
            if(total[i]<low&&total[i]!=-1)
                low=total[i];
        }
        cout<<low;
        if(t>1)
            cout<<endl;
        t--;

    }

}
