#include <iostream>
#include <string.h>
#include<string>
#include <cstring>

using namespace std;

//   string sortarray(string str)
//   {
 //   int i,j;
   //---------------------------------------------------Sorts-----------------------------------------
 //   for( i=0;i<str.length();i++)
 //   {
    //    for( j=0;j<=i;j++)
    //    {
      //      if(str[j]>str[i])
         //   {
            //    char c=str[j];
               // str[j]=str[i];
               // str[i]=c;
            //}
       // }
    //}

    //-----------------------------------Removing duplicates----------------------------
 //       string str2;
  //      str2.push_back(str[0]);

   //     for(i=1;i<str.length();i++)
    //    {
    //        if (str[i]!=str[i-1])
   //         str2.push_back(str[i]);
   //     }

       //cout<<str2<<endl;

//    return str2;
//}
//==============================================================
int main()
{
    int n,i,j,flag,l;
    string str;
    cin>>str;
  //  str=sortarray(str);
    cin>>n;
    string line[n];
    l=str.length();

    for(i=0;i<n;i++)
    {
        cin>>line[i];
      //  line[i]=sortarray(line[i]);
    }


    for(i=0;i<n;i++)
    {
   //  if(str.length()<line[i].length())
   //    cout<<"No\n";
 //    else
 //    {
         for(j=0;j<line[i].length();j++)
         {
             int m=0;
             flag=0;

             while(m<str.length())
            {
             if(line[i][j]==str[m])       flag=1;
             m++;
            }

         if(flag!=1)
         { cout<<"No\n";
          break;    }

          if(j==line[i].length()-1)
            cout<<"Yes\n";
          }

    }

}
//}
