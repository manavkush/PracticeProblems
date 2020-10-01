#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class retrn
{
    public:
    vector<long long int> vec;
    long long int counts;
};

retrn countsplitinv(vector <long long int> arr1,vector <long long int> arr2,long long int n)
    {
        long long int i=0,j=0;
        long long int countsplit=0;
        vector<long long int> arr;
        while(i<n/2&&j<n-n/2)
        {
            if(arr1[i]<=arr2[j])
               { arr.push_back(arr1[i]); i++;
               }
            else
             {  arr.push_back(arr2[j]);
                 countsplit+=(n/2)-i;
                 j++;
             }
        }

        if(i>=n/2)
        {
            for(;j<n-n/2;j++)
                arr.push_back(arr2[j]);
        }

        else if(j>=n-n/2)
        {
            for(;i<n/2;i++)
                arr.push_back(arr1[i]);
        }

        retrn a;
        a.vec=arr;
        a.counts=countsplit;
        arr.clear();
        return a;
    }

retrn invertcount(vector<long long int> vec,long long int n)
        {
            if(n==1)
               {
                   retrn a;
                   a.vec=vec;
                   a.counts=0;
                   return a;
               }

           /*
           else if(n==2)
            {
                if(vec[0]>vec[1])
                {
                    int temp=vec[0];
                    vec[0]=vec[1];
                    vec[1]=temp;

                    retrn a;
                   a.vec=vec;
                   a.counts=1;
                   return a;
                }
                else    {
                    retrn a;
                   a.vec=vec;
                   a.counts=0;
                   return a;}

            }
            */

            else
            {
                ios_base::sync_with_stdio(false);
                cin.tie(NULL);
                retrn a;
                long long int i;
                vector<long long int> arr1,arr2;
                for(i=0;i<n/2;i++)
                    arr1.push_back(vec[i]);
                for(i=n/2;i<n;i++)
                    arr2.push_back(vec[i]);
                retrn x,y,z;
                x=invertcount(arr1,n/2);
                y=invertcount(arr2,n-n/2);
                z=countsplitinv(x.vec,   y.vec,  n);
                a.counts=x.counts+y.counts+z.counts;
                a.vec=z.vec;
                return a;
            }

        }





int main()
{
    vector<long long int> vec;
    fstream new_file;
    new_file.open("a.txt",ios::in);
    if(!new_file)
        cout<<"No such file";
    else
    {
        long long int temp;

        while(!new_file.eof())
            {
                new_file>>temp;
                vec.push_back(temp);
            }

    }


    new_file.close();
    retrn x;
    x=invertcount(vec,100000);
   cout<<x.counts;

}

