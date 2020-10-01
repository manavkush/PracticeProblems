    #include<iostream>
    #include<string>

    using namespace std;
    int main()
    {
        long long int n,i;
        cin>>n;
        long long int vec[4]={0};
        string str1,str2;
        cin>>str1>>str2;
        for(i=0;i<n;i++)
        {
            if(str1[i]=='0'&&str2[i]=='0')
                vec[0]++;
            else if(str1[i]=='0'&&str2[i]=='1')
                vec[1]++;
            else if(str1[i]=='1'&&str2[i]=='0')
                vec[2]++;
            else if(str1[i]=='1'&&str2[i]=='1')
                vec[3]++;
        }
        cout<<(vec[0]*(vec[2]+vec[3])   +   vec[1]*vec[2]);
    }
