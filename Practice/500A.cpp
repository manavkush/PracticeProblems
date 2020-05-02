#include<iostream>

using namespace std;

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      int n,i;
      long long int sum1,sum2;
      cin>>n;
      int x[n],y[n];
      sum1=sum2=0;
      for(i=0;i<n;i++)
      {     cin>>x[i];
             sum1+=x[i];
      }
      for(i=0;i<n;i++)
       {
            cin>>y[i];
            sum2+=y[i];
      }
      if(sum1>=sum2)
            cout<<"Yes" ;
      else  cout<<"No";
}
