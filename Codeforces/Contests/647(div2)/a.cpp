        #include<bits/stdc++.h>
        using namespace std;
        typedef long long ll;
        typedef long double ld;
        typedef long long int lli;
        typedef vector<int> vi;
        typedef vector<long long int> vlli;
        typedef stack<int> si;
        typedef stack<long long int> slli;
        #define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
        #define endl "\n"
        #define pb push_back
        #define mp make_pair
        #define re(i,n)        for(int i=0;i<(n);i++)
        #define re1(i,a,b)       for(int i=(a);i<=(b);i++)
        #define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
        lli pos(lli n)
        {
            if (n == 0)
                return 0;

            lli msb = 0;
            while (n != 0) {
                n = n / 2;
                msb++;
            }

            return ( msb);
        }

        int main()
        {
                FASTIO;
                lli t;
                cin>>t;
                while(t--)
                {
                        lli a,b;
                        cin>>a>>b;
                        if(a==b)
                                cout<<0<<endl;

                        else if(b>a)
                        {
                                lli temp=pos(b)-pos(a);
                                a=a<<temp;
                                if(b==a)
                                {
                                        lli count=0;
                                        count+=temp/3;
                                        temp=temp%3;
                                        count+=temp/2;
                                        temp=temp%2;
                                        count+=temp/1;
                                        cout<<count<<endl;
                                }
                                else
                                {
                                        cout<<-1<<endl;
                                        //cout<<a<<" "<<b<<endl;
                                }
                        }
                        else
                        {
                                lli temp=pos(a)-pos(b);
                                if(temp==0)
                                {
                                        cout<<-1<<endl;
                                       // cout<<"err1"<<endl;
                                }
                                else if(((a>>temp)<<temp)!=a)
                                {
                                        cout<<-1<<endl;
                                        //cout<<"err2 "<<temp<<endl;
                                }
                                else
                                {
                                        a=a>>temp;
                                if(b==a)
                                {
                                        lli count=0;
                                        count+=temp/3;
                                        temp=temp%3;
                                        count+=temp/2;
                                        temp=temp%2;
                                        count+=temp/1;
                                        cout<<count<<endl;
                                }
                                else
                                {
                                        cout<<-1<<endl;
                                        //cout<<a<<" "<<b<<endl;
                                }
                                }
                        }
                }

        }
