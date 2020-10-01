#include <iostream>
#include<vector>

using namespace std;
int main()
{
      int i=6;
      vector <int> vec{1,2,3,4,5,6,8};
      vec.insert(vec.begin()+i,7);

      for(int j=0;j<vec.size();j++)
      {
            //cout<<endl;
            cout<<vec[j]<<" ";
      }
      cout<<endl<<vec[i];
      vec.erase(vec.begin()+i);
            cout<<endl<<vec[i];

      cout<<endl;
      for(int j=0;j<vec.size();j++)
      {
           // cout<<endl;
            cout<<vec[j]<<" ";

      }
      cout<<endl<<i;
}
