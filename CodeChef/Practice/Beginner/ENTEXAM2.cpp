#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      int t;
      long long int k,n,e,i,j;
      long long int m,sum,temp;

      cin>>t;
      while(t--)
      {
             vector<long long int>  vec;
            cin>>n>>k>>e>>m;

            for(i=0;i<n-1;i++)
            {
                  sum=0;
                  for(j=0;j<e;j++)
                  {
                        cin>>temp;
                        sum+=temp;
                  }
                  vec.push_back(sum);
            }
            sum=0;
            for(i=0;i<e-1;i++)
            {
                  cin>>temp;
                  sum+=temp;
            }
            sort(vec.begin(), vec.end());
            if(vec[n-k-1]>=sum+m)     cout<<"Impossible\n";

            else if(vec[n-k-1]>=sum)
            {
                  cout<<(vec[n-k-1]-sum+1)<<"\n";
            }
            else  cout<<"0\n";


      }
}
