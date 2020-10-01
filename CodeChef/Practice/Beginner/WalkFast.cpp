#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;
int main()
{
    int t,n,a,b,c,d,p,q,y,l1,l2,temp,i;
    vector<int>vec;
    cin>>t;
    while(t)
    {
        cin>>n>>a>>b>>c>>d>>p>>q>>y;

        for(i=0;i<n;i++)
        {
                cin>>temp;
                vec.push_back(temp);
        }

        l1=abs(vec[b-1]-vec[a-1])*p;

        if(abs(vec[c-1]-vec[a-1])*p>y)
            cout<<l1<<endl;
        else
        {
            l2=y +abs(vec[d-1]-vec[c-1])*q +abs(vec[d-1]-vec[b-1])*p;
            if(l1<=l2)
                cout<<l1<<endl;
            else
                cout<<l2<<endl;
        }
        vec.clear();
        t--;
    }
}
