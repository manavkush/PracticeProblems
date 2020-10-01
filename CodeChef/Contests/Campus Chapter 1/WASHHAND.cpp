#include<iostream>
#include<vector>

using namespace std;

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      int t;
      long long int n,count,d,i,temp,j,itr,flag;
      long long int vec[10000];
      string str;
      cin>>t;
      while(t--)
      {
            count=0;
            cin>>n;
            int arr[n]={0};
            cin>>str;
            cin>>d;
            for(i=0;i<d;i++)
            {
                  cin>>vec[i];
            }
            for(j=0;j<d;j++)
            {
                  arr[vec[j]-1]=-1;
                  for(i=0;i<n;i++)
                  {
                        flag=0;
                        if(str[i]=='1'&&str[i-1]=='0')
                        {    if(arr[i]!=-1)
                                    str[i-1]='1';

                        }

                        if(str[i]=='1'&&str[i+1]=='0')
                         {
                                    if(arr[i+1]!=-1)
                                    str[i+1]='1';
                                    flag=1;
                         }
                              if(flag)
                              i++;
                  }
            }
            for(i=0;i<n;i++)
            {
                  if(str[i]=='1')
                        count++;
            }
      cout<<count<<"\n";

      }
}
