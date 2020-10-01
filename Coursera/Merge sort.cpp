#include<iostream>
#include<math.h>
#include <vector>

using namespace std;
//----------------------------------function to  sort----------------------------
vector<int> mergesort(vector <int> arr,int n)
{
    int i,j;
     if(n<=2)
    {   if(n==1)    return arr;
        else if(arr[0]>arr[1])
       {
                                                                                         // int temp;
                swap(arr[0],arr[1]);                                                                   //  temp=arr[0];
                                                                                        //   arr[0]=arr[1];
                                                                                       // arr[1]=temp;
       }
        return arr;
    }

    else
    {

        vector <int> v1,v2,t1,t2;
        for(i=0;i<(n/2);i++)
                    v1.push_back(arr[i]);
        for(i=(n/2);i<n;i++)
                    v2.push_back(arr[i]);

        int n1=n/2, n2=n-n1;


        //a.insert(a.end(), b.begin(), b.end());

        t1=mergesort(v1,n1);
        t2=mergesort(v2,n2);

        arr.clear();
       // arr.insert(arr.begin(),t1.begin(),t1.end());
        // arr.insert(arr.begin(),t2.begin(),t2.end());
        i=0;
        j=0;
        while(i<n1&&j<n2)
        {
            if(t1[i]<=t2[j])
               { arr.push_back(t1[i]); i++;
               }
            else
             {arr.push_back(t2[j]); j++; }
        }
        if(i>=n1)
        {
            for(;j<n2;j++)
                arr.push_back(t2[j]);
        }
        else if(j>=n2)
        {
            for(;i<n1;i++)
                arr.push_back(t1[i]);
        }

        return arr;
    }
}
//==============================================================================

int main()
{
    int n,i,temp;
    vector<int> vec,vec2;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        vec.push_back(temp);
    }
    cout<<endl;
    vec2=mergesort(vec,n);
    for(i=0;i<n;i++)
    cout<<vec2[i]<<" ";
}
