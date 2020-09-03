#include<bits/stdc++.h>
using namespace std;
bool test(int n)
{
    if(n<2)
    return 0;
    if(n==2 || n==3)
    {
        return 1;
    }
    if (n%2 == 0 || n%3 == 0) return 0; 
    for(int i=5;i<=sqrt(n);i+=6)
    {
        if(n%i==0 || n%(i+2)==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<char,int>m;
        set<char>st;
        string s;
        cin>>s;
        for(char ch:s)
        {
            m[ch]++;
            st.insert(ch);
        }
        int flag=1;
        if(test(st.size()))
        {
            for(auto i:m)
            {
                if(!test(i.second))
                {
                    flag=0;
                    break;
                }
            }
        }
        if(!test(st.size()))
        {
            flag=0;
        }
        if(flag==1)
        {
            cout<<"YES"<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
}
