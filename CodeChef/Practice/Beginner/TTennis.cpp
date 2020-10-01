#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int n,p1=0,p2=0,j,i;
    string str;
    cin>>n;
    vector<string> vec;
    for(i=0;i<n;i++)
    {
        cin>>str;
        vec.push_back(str);
    }
    //-------------------------------------------------------------------
    for(i=0;i<n;i++)
    {
        str=vec[i];
        j=0;
        p1=0;
        p2=0;
        while(j<20)
        {
            if(str[j]=='0')     p2++;
            else p1++;

            if(p2==11)
            {   cout<<"LOSE\n";
                break;
            }
            else if(p1==11)
            {   cout<<"WIN\n";
                break;
            }
            else if(p1==10&&p2==10)
            {
                do{
                        j++;
                        if(str[j]=='0')     p2++;
                        else p1++;

                    }
                    while(p1-p2!=2&&p2-p1!=2);

                    if(p1-p2==2)     { cout<<"WIN\n";      break;}
                    else {  cout<<"LOSE\n";   break; }
            }
            j++;
        }
    }
}
