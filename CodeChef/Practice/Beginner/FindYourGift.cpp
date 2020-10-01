#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int t,n,x,y,i;
    cin>>t;

    while(t--)
    {
          x=0;
          y=0;
          cin>>n;
          char str[n];
          cin>>str;
          char temp[2];


                  if(str[0]=='L')
                              { x--;        temp[0]='R';
                              temp[1]=str[0];}
                  else if(str[0]=='R')
                              {x++;       temp[0]='L';
                              temp[1]=str[0];
                              }
                  else if(str[0]=='U')
                              {y++;       temp[0]='D';
                              temp[1]=str[0];}
                  else if(str[0]=='D')
                              {y--;         temp[0]='U';
                              temp[1]=str[0];}



          for(i=1;i<n;i++)
          {
                if(str[i]!=str[i-1]&&str[i]!=temp[0]&&str[i]!=temp[1])
                {

                  if(str[i]=='L')
                              { x--;        temp[0]='R';    temp[1]=str[i];}
                  else if(str[i]=='R')
                              {x++;       temp[0]='L';      temp[1]=str[i];}
                  else if(str[i]=='U')
                              {y++;       temp[0]='D';      temp[1]=str[i];}
                  else if(str[i]=='D')
                              {y--;         temp[0]='U';    temp[1]=str[i];}
                }


          }
          cout<<x<<" "<<y<<"\n";
    }

}
