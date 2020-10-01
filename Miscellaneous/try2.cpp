#include <iostream>
#include <vector>

using namespace std;
int main()
{
   int temp,n,i,j;

   cout<<"Enter the number of elements in the array: ";
   cin>>n;
   vector <int> vec;
   cout<<"Enter the numbers: "<<endl;

   for (i=0;i<n;i++)
   {
       cin>>temp;
       vec.push_back(temp);
    }

   for(i=0;i<n-1;i++)
   {
       for(j=0;j<n-1;j++)
       {
           if(vec[j]>vec[j+1])
           {
               temp=vec[j];
               vec[j]=vec[j+1];
               vec[j+1]=temp;
           }
       }
   }
cout<<endl;
   for(i=0;i<n;i++)
   {
       cout<<vec[i]<<endl;
   }
}
