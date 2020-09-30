#include <bits/stdc++.h>
using namespace std;

int dist[100010];
int pred[100010];
bool bfs(vector<int>list[],int sv,int ed,int n)
{
   
   bool *vis=new bool[n+1]();
    for(int i=0;i<=n;i++)
    {
        vis[i] = false; 
        dist[i] = INT_MAX; 
    }
    queue<int>q;
    q.push(sv);
    vis[sv]=1;
    dist[sv]=0;
    while(!q.empty())
    {
        int f=q.front();
       
        q.pop();
        for(int to: list[f])
        {
            if(!vis[to])
            {
                vis[to]=1;
                dist[to]=dist[f]+1;
                q.push(to);
            }
            if(to==ed)
            {
                return 1;
            }
            
        }
    }
    return 0;
  
   
}
int main() {
	int n,m;
	cin >> n>>m;
    vector<int>list[n+1];
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
       list[x].push_back(y);
       list[y].push_back(x);
    }
    int sv,ed;
    cin>>sv>>ed;
    
    int ans=bfs(list,sv,ed,n);
    if(ans)
    {
        cout<<dist[ed];
    }
    else{
        cout<<-1;
    }
    
}
	
    
