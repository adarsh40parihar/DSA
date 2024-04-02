// dp[i][j] = shortest distance from node i to node j 
// initially all dist[i][j]= INFINITY if there is no edge of i to j 
// dist[i][j] = weight(i,j) if there is edge from it to j 
// dist[i][i]=0

for(int k=0; k<n; k++)
{
    for(int i=0; i<n; i++)
	{	
		for(int j=0; j<n; j++)
            {
            dp[i][j]  = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
	}
}
