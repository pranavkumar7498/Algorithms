#include<bits/stdc++.h>
using namespace std;
int color[100005];

bool bipartite(vector<int>list[],int n)
{
    queue<int>q;
	for(int i=0;i<=n;i++)
    {
        color[i]=-1;
    }
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
           q.push(i);
           color[i]=0;
            while(!q.empty())
            {
                int v=q.front();
                q.pop();
                for(int u: list[v])
                {
                    if(color[u]==-1)
                    {
                        color[u]=color[v] ^ 1;
                        q.push(u);
                    }
                    else
                    {
                        ans &=(color[u] !=color[v]);
                    }
                }
            }
        }
    }
    return ans;
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

    bool ans=bipartite(list,n);
    if(ans)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}
