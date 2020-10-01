#include<iostream>
//#include<stdio.h>

using namespace std;
int main()
{
    int n,i,j,counter,a,b;

    cin>>n;
    char ch[100];
   // int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>a;
        cin>>b;
        counter=0;

        for(j=0;j<a;j++)
                cin>>ch[j];

        for(j=a-1;j>=a-b;j--)
        {   if(ch[j]=='H')
            {
                for(int m=0;m<j;m++)
                    {
                        if(ch[m]=='T')
                            ch[m]=='H';
                        else ch[m]=='T';
                    }
            }
        }
        for(j=0;j<a-b;j++)
        {
            if(ch[j]=='H')
                counter++;
        }
        cout<<counter<<endl;

    }

}
