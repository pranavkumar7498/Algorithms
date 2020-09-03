#include<bits/stdc++.h>
using namespace std;
bool perfect(int n)
{
      long double x=sqrt(n);
     if(floor(x)-x==0)
     return 1;
 else
   return 0;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;cin>>a[i++]);
   vector<int>v;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=i;j<=n;j++)
        {
            sum+=a[j];
            v.push_back(sum);
        }
    }
    int count=0;
    for(int i=0;i<v.size();i++)
    {
        if(perfect(v[i]))
        {
            count++;
        }
    }
    cout<<count;
    
    
}
