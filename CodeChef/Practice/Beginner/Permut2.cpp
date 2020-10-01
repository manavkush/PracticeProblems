#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n,i;
    vector <string> vec;
    cin>>n;
    while(n!=0)
    {
     int a[n],b[n];
     for(i=0; i<n; i++)
       cin>>a[i];
     for(i=0; i<n;i++)
     {
         int temp=a[i];
         b[temp-1]=i+1;
     }
     int flag=0;
     for(i=0;i<n;i++)
     {
         if(a[i]!=b[i])
        { flag=1;
          break; }
     }
     if(flag==0)
     vec.push_back("ambiguous");
     else vec.push_back("not ambiguous");
     cin>>n;
    }
    for(i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<endl;
    }
    return 0;
}
