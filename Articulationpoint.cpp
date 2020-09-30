#include<bits/stdc++.h>
using namespace std;
int ap[10010];
int tim[10010];
int low[10010];
int t=0;
void dfs(vector<int>list[],int sv,int p,bool *vis)
{
    vis[sv]=1;
    low[sv]=tim[sv]=++t;
    int ch=0;
    for(auto to:list[sv])
    {
        if(to==p)
        {
            continue;
        }
        
        if(!vis[to])      
        {
            ch++;
            dfs(list,to,sv,vis);
            low[sv]=min(low[sv],low[to]);
            if(p!=-1 && tim[sv] <= low[to])
            {
                ap[sv]=1;
            }
           if(p==-1 and ch>1) 
           {
               ap[sv]=1;
            }
        }
       else
        {
            low[sv]=min(low[sv],tim[to]);
        }
    }
    
}
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n];
	//for(int i=0;i<n;cin>>a[i++]);
	vector<int>list[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		list[u-1].push_back(v-1);
		list[v-1].push_back(u-1);
	}
	memset(ap,0,sizeof(ap));
	memset(tim,0,sizeof(tim));
	memset(low,0,sizeof(low));

	bool *vis=new bool[n+1]();

	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(list,i,-1,vis);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(ap[i])
		cout<<i+1<" ";
	}

}
