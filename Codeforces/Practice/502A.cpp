#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
      int n,a,b,c,d,i;
      cin>>n;
      vector <int> vec;
      for(i=0;i<n;i++)
      {
            cin>>a>>b>>c>>d;
            vec.push_back(a+b+c+d);

      }
      a=vec[0];
      sort(vec.begin(),vec.end(),greater<int>());
      for(i=0;i<n;i++)
      {
            if(vec[i]==a)
            {
                  cout<<i+1;
                  return 0;
            }
      }

}
