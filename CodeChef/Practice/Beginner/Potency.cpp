#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
int main()
{
    int t,n,i,j,flag;
    long long int m,temp;
    vector <long long int> arr;
    cin>>t;
    while(t)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            arr.push_back(temp);
        }
        flag=0;
        for(i=0;i<n-1;i++)
        {
            for(j=1;j<n;j++)
            {
                if(arr[j]+arr[i]==m)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(flag==1)
            cout<<"YES\n";
        else    cout<<"NO\n";

        t--;
        arr.clear();
    }
}
