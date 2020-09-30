#include<bits/stdc++.h>
using namespace std;
int t=0;
void dfs(vector<int>list[],int sv,int p,bool *vis,int *tim,int *low)
{
	vis[sv]=1;
	tim[sv]=low[sv]=++t;

	for(auto to:list[sv])
	{
		if(to==p) continue;
		if(vis[to])
		{
			low[sv]=min(low[sv],tim[to]);
		}
		else
		{			
			dfs(list,to,sv,vis,tim,low);
			low[sv]=min(low[sv],low[to]);
			if(low[to]>tim[sv])
			{
				cout<<sv<<" "<<to<<endl;
			}			
		}
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>list[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		list[u].push_back(v);
		list[v].push_back(u);
	}
	
	int *tim=new int[n+1];
	int *low=new int[n+1];
	for(int i=0;i<n+1;i++)
	{
		tim[i]=0;
		low[i]=0;
	}
	bool *vis=new bool[n]();
	int sv;
	cin>>sv;
	dfs(list,sv,-1,vis,tim,low);
}
