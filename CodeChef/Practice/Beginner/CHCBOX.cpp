#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int t,n,temp,i,max,count,dmax;
    cin>>t;
    vector<int> vec, arr;

    while(t--)
    {
          cin>>n;
          cin>>temp;
          max=temp;
          count=1;
          //vec.push_back(temp);
          arr.push_back(0);
           //========================================================================

          for(i=1;i<n;i++)
          {
                cin>>temp;
              //  vec.push_back(temp);
                if(temp>max)
                {
                      count=1;
                      max=temp;
                      arr.clear();
                      arr.push_back(i);
                }
                else if(temp==max)
                  {     count++;
                         arr.push_back(i);
                  }
          }

          //==========================================================================

          if(count>n/2)
                cout<<"0\n";
          else if(count==1)
            cout<<n/2<<"\n";

          else
          {
                dmax=(n-1)-arr[count-1]+arr[0];
                for(i=1;i<count;i++)
                {
                      if(arr[i]-arr[i-1]>dmax)
                              dmax=arr[i]-arr[i-1]-1;
                }


                if (dmax<n/2)
                  cout<<"0\n";

                else
                {
                      cout<<dmax-(n/2)+1<<"\n";
                }
          }
           vec.clear();
           arr.clear();
    }

}
