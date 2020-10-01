#include<bits/stdc++.h>

using namespace std;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      int t,i,j;
      int n,m,k;
      cin>>t;
      while(t--)
      {

            cin>>n>>m>>k;
            int freq[n];
            int arr[n][k];
            for(i=0;i<n;i++)
            {
                   unordered_map<int,int> hash;

                  for(j=0;j<k;j++)
                  {
                        cin>>arr[i][j];
                        hash[arr[i][j]]++;
                  }
                  int max_count = 0, res = -1;
                  for (auto j : hash)
                  {
                        if (max_count < j.second)
                        {
                        res = j.first;
                        max_count = j.second;
                        }
                  }
                  freq[i]=res;
            }
            for(i=0;i<n;i++)
                  cout<<freq[i]<<" ";
            cout<<"\n";

      }
}
