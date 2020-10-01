#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int t,n,i,temp;
    cin>>t;
    string str;
    while(t--)
    {
        map<string, vector<int> > mymap;


        cin>>n;

        for(i=0;i<n;i++)
        {


            cin>>str;
            if ( mymap.find(str) == mymap.end() )
                {
                    cin>>temp;
                    vector <int> vec;
                    vec.push_back(0);
                    vec.push_back(0);

                    if(temp)
                                vec[1]++;
                    else    vec[0]++;

                    mymap [str]=vec;
                    vec.clear();
                }
            else
                {
                    cin>>temp;
                    if(temp)    mymap[str][1]++;
                    else    mymap[str][0]++;
                }


        }
        int count=0;
        map< string,vector<int> >::iterator itr;
        for(itr=mymap.begin()     ;    itr!=mymap.end()  ;   ++itr)
        {
            if(itr->second[0]>itr->second[1])
                count+=itr->second[0];
            else count+=itr->second[1];
        }
        cout<<count<<"\n";
    }
}
