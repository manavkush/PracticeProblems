#include<iostream>

using namespace std;

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      int temp;
      cin>>temp;

      while(temp!=42)
      {
            cout<<temp<<"\n";
            cin>>temp;
      }
}
