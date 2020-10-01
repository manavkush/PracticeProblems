#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
int main()
{
    long long int t,x[2],y[2],z[2],score[2];
    cin>>t;
    while(t)
    {
        cin>>x[0]>>y[0]>>z[0];
        cin>>x[1]>>y[1]>>z[1];

        score[0]=10*x[0]-30*y[0]+150*z[0];
        score[1]=10*x[1]-30*y[1]+150*z[1];

        if(score[0]>score[1])   cout<<1<<endl;
        else if(score[0]<score[1])   cout<<2<<endl;
        else if(score[0]==score[1])   cout<<5.6<<endl;

        t--;

    }
}
