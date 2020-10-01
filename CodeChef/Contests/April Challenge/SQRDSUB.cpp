#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>

using namespace std;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      int t;
      vector <long long int> vec;
      long long int num,n,temp,sum,count,i,arr[100005];
      cin>>t;
      while(t--)
      {
            cin>>n;
            sum=0;

            for(i=0;i<n;i++)
            {
                  cin>>temp;
                  if(temp%2  !=  0)
                         arr[i]=0;

                  else if(temp%4==0)
                        arr[i]=2;

                  else
                  {
                        arr[i]=1;
                        vec.push_back(i);
                  }
            }
           // for(i=0;i<n;i++)
          //        cout<<arr[i]<<" ";

            sum=0;
            count=0;
            for(i=0;i<n;i++)
            {
                  if(arr[i]==1)
                        {
                              sum=sum+(count*(count+1))/2;
                              count=0;
                        }
                  else
                        count++;
            }

            if(count!=0)
                  sum=sum+(count*(count+1))/2;

            num=vec.size();
            //cout<<sum<<" ";

            if(num>1)
            {
                  for(i=1 ;i<num-1;i++)
                  {
                        sum+=((i+1)/2)*(vec[i+1]-vec[i]);
                  }

                        sum+=(num/2)*(n-vec[num-1]  );
            }
           cout<<sum<<"\n";
           vec.clear();


      }
}
