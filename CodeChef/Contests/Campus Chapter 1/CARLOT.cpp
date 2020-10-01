#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      int t;
      ;
      cin>>t;
      while(t--)
      {
            pair <int,int> temp;
            cin>>m>>n;
            vector < pair <int,int > > arr;
            int vec[m][n]={0};

            for(i=0;i<m;i++)
            {
                  for(j=0;j<n;j++)
                  {
                        cin>>temp;
                        if(temp=='P')
                              {
                                    vec[i][j]=1;
                                    arr.push_back( make_pair( i ,j ));
                              }
                  }
            }
            count=0;
            temp=vec[0];
            for(i=1;i<vec.size();i++)
            {
                  if(temp.first%2==0)
                  {
                  if(vec[i].first==temp.first)
                  {

                        count=count+temp
                  }
                  }
            }
}
