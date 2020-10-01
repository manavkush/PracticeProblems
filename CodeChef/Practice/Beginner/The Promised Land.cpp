#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int t,n,m,x,y,sum,temp,i,j,s;
    vector<int> vec1,vec2;
    cin>>t;
    while (t)
    {
        cin>>n>>m;
        //int arr[n][m];

        cin>>x>>y>>s;
//================================================================
    if(x!=0&&y!=0)
    {

        int arrx[x+2],arry[y+2];

        arrx[0]=0;
        arry[0]=0;
        arrx[x+1]=n+1;
        arry[y+1]=m+1;

        for(i=1;i<=x;i++)
        cin>>arrx[i];
        for(i=1;i<=y;i++)
        cin>>arry[i];

        for(i=1;i<=x+1;i++)
        {
            temp=arrx[i]-arrx[i-1]-1;
            if(temp>=s)
                vec1.push_back(temp/s);
        }

        for(i=1;i<=y+1;i++)
        {
            temp=arry[i]-arry[i-1]-1;
            if(temp>=s)
                vec2.push_back(temp/s);
        }

        sum=0;

        for(i=0;i<vec1.size();i++)
        {

            for(j=0;j<vec2.size();j++)
            {

                sum=sum+vec1[i]*vec2[j];
            }
        }
    }
    //--------------------------------------------------------
    else if(x==0&&y!=0)
        {
            int arry[y+2];
        arry[0]=0;

        arry[y+1]=m+1;


        for(i=1;i<=y;i++)
        cin>>arry[i];

        for(i=1;i<=y+1;i++)
        {
            temp=arry[i]-arry[i-1]-1;
            if(temp>=s)
                vec2.push_back(temp/s);
        }

        sum=0;

            for(j=0;j<vec2.size();j++)
            {

                sum=sum+vec2[j]*(n/s);
            }
        }
    //=============================================================

       else if(x!=0&&y==0)
        {
            int arrx[x+2];
        arrx[0]=0;

        arrx[x+1]=n+1;


        for(i=1;i<=x;i++)
        cin>>arrx[i];

        for(i=1;i<=x+1;i++)
        {
            temp=arrx[i]-arrx[i-1]-1;
            if(temp>=s)
                vec1.push_back(temp/s);
        }

        sum=0;

            for(j=0;j<vec1.size();j++)
            {

                sum=sum+vec1[j]*(m/s);
            }

    }
    else if(x==0&&y==0)
    {
        sum=(n/s)*(m/s);
    }
    cout<<sum<<endl;
    vec1.clear();
    vec2.clear();
t--;
}
}
