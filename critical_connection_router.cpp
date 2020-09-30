  vector<vector<int>>ans;
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
				ans.push_back({sv,to});
			}			
		}
	}
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) 
    {
           vector<int>list[n+1];
        	for(auto c:con)
            {
                list[c[0]].push_back(c[1]);
                list[c[1]].push_back(c[0]);
            }
	int *tim=new int[n+1];
	int *low=new int[n+1];
	for(int i=0;i<n+1;i++)
	{
		tim[i]=0;
		low[i]=0;
	}
	bool *vis=new bool[n+1]();
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
               dfs(list,i,-1,vis,tim,low);
            }
        }
        
        return ans;
        
    }
