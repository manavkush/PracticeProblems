#include<iostream>

using namespace std;
 int main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       int t;
       cin>>t;
       long long int n,count,i;
       while(t--)
       {
             cin>>n;
             if(n<=3)
            {
                  cout<<"1\n";
                  cout<<n<<" ";
                  for(i=1;i<=n;i++)
                  {
                        cout<<i<<" ";
                  }
                  cout<<"\n";
            }
            else
            {
                  cout<<n/2<<"\n";
                  cout<<"3 1 2 3\n";

                  if(n%2==1)
                  {
                        for(i=2;i<=n/2;i++)
                              cout<<"2 "<<2*i<<" "<<2*i+1<<"\n";
                  }
                  else
                  {
                        for(i=2;i<n/2;i++)
                              cout<<"2 "<<2*i<<" "<<2*i+1<<"\n";
                        cout<<"1 "<<n<<"\n";
                  }
            }

       }

}
