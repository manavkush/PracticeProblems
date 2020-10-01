#include <bits/stdc++.h>
#define lli long long int

using namespace std;
int main()
{   
    long long int n,curr=1;
    cin>>n;
    while(n%2==0)
    {
        n/=2;
        curr=2;
    }
    for(int i=3;i<=sqrt(n);i=i+2)
    {
        while((n%i)==0)
        {
            n/=i;
            curr=i;
        }
    }
    if(n>2)
        curr=n;
    cout<<curr;

}

