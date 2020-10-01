#include<iostream>

int  countOnes (int n)
{
    int count=0;
    while (n!=0)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}
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
