#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n,k,bestfriends=0;
    int i,j;        // declaring counters for the loops
    string str;   // temporary string for storing the names

    // inputing the variables
    cin>>n;
    cin>>k;

    vector<string> names;       // vector ( array ) for storing the names

    for(i=0;i<n;i++)
    {
        cin>>str;
        names.push_back(str);           // Entering each name in the vector
    }
//--------------------------------------------------------------------------------------------
     for(i=0;i<n-1;i++)

      {

            j=i+1;
            while(j<n&&j<i+k+1)
            {

                if ( names[i].length()==names[j].length() )             // checking if the lengths of the strings are equal
                        bestfriends++;

                j++;
            }


     }
     cout<<endl<<bestfriends;


}


