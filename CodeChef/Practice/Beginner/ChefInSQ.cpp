#include<bits/stdc++.h>

using namespace std;

long long int combi(long long int n, long long int k)
{
    long long int ans=1;
    k=k>n-k?n-k:k;
    long long int j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t,n,k,i,key,count;
    vector <long long int> vec;
    cin>>t;

    while(t--)
    {

        cin>>n>>k;
        for(i=0;i<n;i++)
        {
            cin>>key;
            vec.push_back(key);
        }
        sort(vec.begin(),vec.end());
        count=0;
        i=k-1;
        while( vec[i]==vec[i+1]  && i<n-1 )
            {   count++;   i++;}
        i=k-1;
        key=1;
        while(vec[i]==vec[i-1]  && i>0)
            {   key++;    i--;}

        cout<<combi(key+count,key)<<"\n";
        vec.clear();
    }
}
