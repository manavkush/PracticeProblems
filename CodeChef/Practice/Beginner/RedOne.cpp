#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t)
    {
        cin>>n;
        num=n;
        for(i=0;i<n-1;i++)
        {
            num=2*num + num*num;
        }
        cout<<num;
    }
}
