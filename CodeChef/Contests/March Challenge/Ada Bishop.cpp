#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int t,c,r,i,num,counts;
    cin>>t;
    vector<int> vec;
    while(t)
    {
        counts=0;

        cin>>r>>c;
  //-------------------------------------------------------------------
    if((r+c)%2==0)
    {

        if(r!=c)
            {
                vec.push_back(  (r+c)/2);
                vec.push_back((r+c)/2  );
                counts++;
            }

        if(r!=1||c!=1)
        {    vec.push_back(1);
             vec.push_back(1);
             counts++;
        }

        for(i=2;i<=8;i++)
        {
            vec.push_back(i);
            vec.push_back(i);
            counts++;

            if(i==8)
                break;
            if(i<=4)
            {
                vec.push_back(1);
                vec.push_back(2*i-1);
                vec.push_back(2*i-1);
                vec.push_back(1);

                vec.push_back(i);
                vec.push_back(i);

                counts=counts+3;
            }
            else
            {
                vec.push_back(8);
                vec.push_back(2*i-8);
                vec.push_back(2*i-8);
                vec.push_back(8);
                vec.push_back(i);
                vec.push_back(i);
                counts=counts+3;
            }
        }
    }
    //--------------------------------------------------------------------------------------
    else
        {


        if(r+c !=9)
            {
                vec.push_back(  (9+r-c)/2);
                vec.push_back((9+c-r)/2  );
                counts++;
            }

        if(r!=8||c!=1)
        {    vec.push_back(8);
             vec.push_back(1);
             counts++;
        }

        for(i=7;i>=1;i--)
        {
            vec.push_back(i);
            vec.push_back(9-i);
            counts++;

            if(i==1)
                    break;
            if(i<=4)
            {
                vec.push_back(2*i-1);
                vec.push_back(8);
                vec.push_back(1);
                vec.push_back(10-2*i);

                vec.push_back(i);
                vec.push_back(9-i);

                counts=counts+3;
            }
            else
            {
                vec.push_back(8);
                vec.push_back(17-2*i);
                vec.push_back(2*i-8);
                vec.push_back(1);
                vec.push_back(i);
                vec.push_back(9-i);
                counts=counts+3;
            }
        }

            }






        cout<<counts<<endl;
        for(i=0;i<vec.size();i=i+2)
        {
            cout<<vec[i]<<" "<<vec[i+1]<<endl;
        }

        t--;
    }
}
