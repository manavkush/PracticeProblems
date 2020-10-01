#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{   int n,m,i,temp;     // declaring the no of children, colors,  counters and temporary variables
    cin>>n;
    cin>>m;
    vector<int> vec;    // temporary vector
    for(i=0;i<m;i++)
    {
       cin>>temp;
        vec.push_back(temp);            // input in vector
    }

    int arr[n]={0};                         // distribution array whose all elements are initialized to 0
    for(i=0;i<m;i++)
    {
        arr[i]=vec[i];              // copying the elements to array a
    }
    int  x=m;                           // variable to be used in the loop

    while(arr[n-1]==0)
    {
        temp=distance(arr,max_element (arr , arr+n));            // tells the index of the highest element
        arr[x]=arr[temp]/2;
        arr[temp]=arr[temp]-arr[x];                                             //divides the highest color marbles to the vacant
        x++;
    }
    temp=*max_element(arr,arr+n);           // finds the maximum element
    cout<<temp;

}
