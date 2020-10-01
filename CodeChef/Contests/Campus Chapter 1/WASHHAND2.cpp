#include<iostream>
#include<vector>

using namespace std;

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      int t;
      long long int n,count,d,i,temp,j,itr,flag;
      long long int vec[10001];
      vector <long long int> vec2;
      string str;
      cin>>t;
      while(t--)
      {
            count=0;
            cin>>n;
            long long int arr[n]={0};
            cin>>str;
            cin>>d;
            for(i=0;i<d;i++)
            {
                  cin>>vec[i];
            }

            for(i=0;i<n;i++)
                  if(str[i]=='1')
                        vec2.push_back(i);

            for(j=0;j<d;j++)
            {
                  arr[vec[j]-1]=-1;
                  for(i=0;i<vec2.size()&&i>=0;i++)
                  {
                        //flag=0;
                        temp=vec2[i];
                        if(arr[temp]!=-1&&str[temp-1]!='1')
                        {

                              str[temp-1]='1';
                              vec2.insert(vec2.begin()+i,temp-1);
                              i++;

                        }

                         if(arr[temp+1]!=-1&&str[temp+1]!='1')
                         {
                                    str[temp+1]='1';
                                   vec2.insert(vec2.begin()+i,temp+1);
                                    i++;

                         }

                             vec2.erase(vec2.begin()+i);
                             if(vec2.size()!=0)
                              i--;

                  }
                        //  for(i=0;i<vec2.size();i++)
                                //    {
                            //              cout<<vec2[i]<<" ";
                               //     }
                                //    cout<<endl;

            }
            for(i=0;i<n;i++)
            {
                 // cout<<str[i]<<" ";
                  if(str[i]=='1')
                        count++;
            }

      cout<<count<<"\n";
      vec2.clear();

      }
}
