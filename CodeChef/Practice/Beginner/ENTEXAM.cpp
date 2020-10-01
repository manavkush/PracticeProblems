#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second > b.second);
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      int t,k,n,e,i,j;
      long long int m,sum,temp;
      cin>>t;
      while(t--)
      {
            cin>>n>>k>>e>>m;
            vector<pair<int,long long int>>  vec;
            for(i=0;i<n-1;i++)
            {
                  sum=0;
                  for(j=0;j<e;j++)
                  {
                        cin>>temp;
                        sum+=temp;
                  }
                  vec.push_back(make_pair(i,sum));
            }
            sum=0;
            for(i=0;i<e-1;i++)
            {
                  cin>>temp;
                  sum+=temp;
            }
            sort(vec.begin(), vec.end(), sortbysec);
            if(vec[k-1].second>=sum+m)     cout<<"Impossible\n";

            else
            {
                  cout<<(vec[k-1].second-sum+1)<<"\n";
            }

      }
}
