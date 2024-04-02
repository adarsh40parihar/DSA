vector<pair<int,pii>> e;
//input all directed weighted edges into e
//dp[i] = shortest distance to node i
for(auto &i:dp) i=INF;
dp[s]=0;
for(int i=1; i<=n-1; i++)
{
     for(auto e: edges)
     {
		int u=e.first;
      	int v=e.second.first;
      	int w=e.second.second;
      	if(dp[u]+w <dp[v])
        {
             dp[v]=dp[u]+w;
        }
     }
}