#include<iostream>

using namespace std;
int main()
{
    long long int arr[100000],n,b,j,t,sum,i,temp;
    cin>>t;
    for(i=0;i<t;i++)
    {
        sum=0;
        cin>>n>>b;

        for(j=0;j<n;j++)
        cin>>arr[j];

        for(j=0;j<n;j++)
        {
            temp=arr[j]%b;
            sum+=temp;
        }
        sum=sum%b;
        cout<<sum<<endl;
    }
}
