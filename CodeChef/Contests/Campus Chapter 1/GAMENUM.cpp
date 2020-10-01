#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;
long long int pow(long long int a,long long int b)
{
      long long int x=1;
      while(b--)
      {
            x=x*a;
      }
      return x;
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      int t;
      long long int a,b,n1,n2,max_idx,max_val,i,temp,x;
      cin>>t;
      while(t--)
      {
            cin>>a;
            cin>>b;

            n1=int(floor(log(a)/log(2))+1);
            n2=int(floor(log(b)/log(2))+1);


            if(n2<n1)   n2=n1;

            max_idx=0;
            max_val=a^b;

            x=pow(2,n2-1);

            for(i=1;i<n2;i++)
            {
                 temp= b%2;
                 b=(b-temp)/2;
                 b+=temp*(x);
                  temp=b^a;
                  if(max_val<temp)
                  {     max_val=temp;
                        max_idx=i;
                  }
            }

            cout<<max_idx<<" "<<max_val<<"\n";
      }
}















