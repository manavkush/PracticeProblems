#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      long long int n,x,i;
      cin>>n>>x;
      long long int  vec1[100002]={0},vec2[100002]={0};
      long long int a[n];
      for(i=0;i<n;i++)
      {
            cin>>a[i];
            vec1[a[i]]++;
            vec2[a[i]&x]++;
      }
      for(i=0;i<n;i++)
      {
            if(vec1[a[i]]>=2)
            {
                  cout<<"0";
                  return 0;
            }
      }

      for(i=0;i<n;i++)
            {
                  if(vec1[a[i]]  && vec1[a[i]&x]  && a[i]!=(a[i]&x))
                  {     cout<<"1";
                         return 0;
                  }
            }
      for(i=0;i<n;i++)
      {
            if(vec2[a[i]&x]>=2)
            {
                  cout<<"2";
                  return 0;
            }
      }
      cout<<"-1";
}


