#include<iostream>
#include<vector>
using namespace std;

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      int t,i,min,n,temp;
      vector<int> vec;
      cin>>t;
      while(t--)
      {
            cin>>n;
            for(i=0;i<n;i++)
            {
                  cin>>temp;
                  if(temp==1)
                  vec.push_back(i);
            }
            if(vec.size()<2)
                  cout<<"YES\n";
            else
            {
                  min=vec[1]-vec[0];
                  for(i=1;i<vec.size();i++)
                  {
                        if(min>vec[i]-vec[i-1])
                              min=vec[i]-vec[i-1];
                  }
                  if(min<6)   cout<<"NO\n";
                  else cout<<"YES\n";
            }
            vec.clear();

      }
}
