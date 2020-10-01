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
      long long int k,n,temp,sum,count,i,arr[100005];
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
            //====================================================
            for(i=0;i<n;i++)
            {
                  if(arr[i]==2)
                  {
                        sum+= (n-i);
                       // cout<<sum<<" ";
                  }

                  else if(arr[i]==1)
                  {
                        count=i+1;
                        while(arr[count]<1&&count<n)
                              count++;
                        sum+= (n-count);
                        //cout<<sum<<" ";
                  }
            //======================================================================
                  else if(arr[i]==0)
                  {
                        count=1;
                        k=i+1;
                        while(arr[k]==0&&k<n)
                        {
                              k++;
                              count++;
                        }

                        sum+=(count*(count+1))/2  ;

            //=========================================
                        if(k<n)
                        {
                               if(arr[k]==2)
                              {
                                    sum+=count*(n-k);
                                    i=k-1;
                                    //cout<<sum<<" ";
                              }

                              else if(arr[k]==1)
                              {

                                     temp=k+1;
                                    while(arr[temp]<1&&temp<n)
                                          temp++;
                                    if(temp!=n)
                                          {
                                                sum+=count*(n-temp);
                                                 i=k-1;
                                               //  cout<<sum<<" ";
                                          }

                                    else
                                    { i=k; //cout<<sum<<" ";
                                    }
                              }
                        }
                        else
                              { i=n-1; //cout<<sum<<" ";
                              }

                  }

            }


           cout<<sum<<"\n";
           vec.clear();


      }
}
