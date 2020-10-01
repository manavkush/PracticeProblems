#include<iostream>

long int  countOnes (long long int n)
{
    int count=0;
    while (n!=0)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}
int t,n;
using namespace std;
int main()
{
    cin>>t;
    while(t)
    {
        cin>>n;
        cout<<countOnes(n)<<endl;
        t--;
    }
}
