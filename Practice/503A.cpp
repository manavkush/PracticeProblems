#include<iostream>
#include<stdlib.h>

using namespace std;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      long long int n,h,a,b,k,t1,t2,f1,f2,sum;
      cin>>n>>h>>a>>b>>k;
      while(k--)
      {
            cin>>t1>>f1>>t2>>f2;
            if(t1!=t2)
            {

            if(f1>b)
                        sum=f1-b +abs(t2-t1)+abs(f2-b);
            else if(f1<a)
                        sum=a-f1 +abs(t2-t1)+abs(f2-a);
            else
                        sum=abs(t2-t1) +abs(f2-f1);
            }
            else
                  sum=abs(f1-f2);

            cout<<sum<<"\n";
      }
}
