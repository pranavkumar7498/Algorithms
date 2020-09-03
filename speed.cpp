#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
       
        cin>>n;
         int a[n];
        for(int i=0;i<n;cin>>a[i++]);
        int count=1;
        int i=0;
        int j=1;
        int maxs=a[0];
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        while(j<n)
        {
            if(a[j]<=maxs)
            {
                count++;  
                maxs=a[j];
            }
            j++;
        }
         cout<<count<<endl;
    }
}
