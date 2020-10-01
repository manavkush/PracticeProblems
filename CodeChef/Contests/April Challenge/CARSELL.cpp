#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      int t;
      long long int n,temp,i,sum;
      vector<long long int> vec;
      cin>>t;
      while(t--)
      {
            sum=0;
            cin>>n;
            for(i=0;i<n;i++)
            {
                  cin>>temp;
                  vec.push_back(temp);
            }

            sort(vec.begin(),vec.end());
            for(i=n-1;i>=0;i--)
            {
                  if(vec[i]+i-n+1>0)
                        sum=sum+vec[i]+i-(n-1);
            }
            sum=sum%(1000000007);
            cout<<sum<<"\n";
            vec.clear();
      }
}
