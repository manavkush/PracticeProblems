#include<iostream>
#include<vector>
using namespace std;

//---------------------------------------------------------------Sort Function------------------------------------------------
void insertSort(vector<int> vec,int n)
{    int i;
      for(int j=1;j<n;j++)
    {
        int temp=vec[j];
         i=j-1;
        while(i>=0&&vec[i]>temp)
        {
            vec[i+1]=vec[i];
            i--;

        }
        vec[i+1]=temp;
    }
    cout<<endl;

    for(i=0;i<n;i++)
    {
        cout<<vec[i]<<endl;
    }

}

//----------------------------------------------------- Main function-----------------------------------------------------------------------
int main()
{
    vector <int> vec;
    int i,temp;
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    cout<<"Enter the elements: \n";
    for(i=0;i<n;i++)
    {
        cin>>temp;
        vec.push_back(temp);
    }

    insertSort(vec,n);

}
