//selection sort program

#include<iostream>
#include<vector>

using namespace std;
int i,n;
void swapf(vector <int> arr,int firstind, int secind)
{
    int temp;
    temp=arr[firstind];
    arr[firstind]=arr[secind];
    arr[secind]=temp;
}

int maxindex(vector <int> vec2, int startidx, int n)                // function to find the maximum index
{
    int idx=startidx;
    for(i=startidx;i<n-1;i++)
    {
        if(vec2[i+1]>vec2[i])
            idx=i+1;
    }
    return idx;
}

int main()
{
    int maxid,temp;
    cout<<"Enter the number of elements in the array: ";
   cin>>n;
   vector <int> vec;
   cout<<"Enter the numbers: "<<endl;

   for (i=0;i<n;i++)                    // Entering the vector
   {
       cin>>temp;
       vec.push_back(temp);
    }

  for(i=0;i<n-1;i++)
  {
      maxid=maxindex(vec, i,n);                 // Calculating the index of max value
    swapf(vec,vec[i],vec[maxid]);                   // swapping
  }
cout<<endl;
 for(i=0;i<n;i++)
   {
       cout<<vec[i]<<endl;
   }
}

