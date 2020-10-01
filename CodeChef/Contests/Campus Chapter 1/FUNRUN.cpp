#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      long long int t,n,i;
      long long int arr1[100002],arr2[100002];
      cin>>t;
      while(t--)
      {
            cin>>n;

      for(i=0;i<n;i++)
            cin>>arr1[i];

      for(i=0;i<n;i++)
            cin>>arr2[i];

      sort(arr1,arr1+n);
      sort(arr2,arr2+n);
      if(arr1[n-1]==arr2[n-1])
            cout<<"NO\n";
      else cout<<"YES\n";
      }
}
