#include<iostream>
#include<vector>
using namespace std;

void main()
{
    int n,k,bestfriends=0;
    string ipname;      // input name
    cin>>n;
    cin>>k;

    vector<string> names;

    for(i=0;i<n;i++)
    {
        cin>>str;
        names.push_back(str);           // Entering each name in the vector
    }


    for(i=0;i<n-1;i++)

        j=i+1
        while(j<n&&j<i+k+1)
        {

            if ( names[i].length()==names[j].length() )
                bestfriends++;


        }
    cout<<endl<<bestfriends;

}


