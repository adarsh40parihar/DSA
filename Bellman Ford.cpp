vector<pair<int,pii>> e;
//input all directed weighted edges into e
//dp[i] = shortest distance to node i
vector<int> dis(n + 1, 1e18);
dis[s] = 0;
for(int i=1; i<=n-1; i++)
{
     for(auto e: edges)
     {
		int u=e.first;
      	int v=e.second.first;
      	int w=e.second.second;
          if (dis[u] + w < dis[v])
          {
               dis[v] = dis[u] + w;
          }
     }
}
for (auto e : edges)
{
     int u = e.first;
     int v = e.second.first;
     int w = e.second.second;
     if (dis[u] + w < dis[v])
     {
         cout<<"Negative cycle found".
     }
}




// Cycle Trace back and print:
void bellmanFord_TraceBackCycle()
{ // use int
     int n, e;
     cin >> n >> e;
     vector<pair<int, pair<int, int>>> edges;
     while (e--)
     {
          int u, v, w;
          cin >> u >> v >> w;
          edges.pb({u, {v, w}});
     }
     vector<int> dis(n + 1, 1e18);

     // for trace back
     vector<int> parent(n + 1, -1);
     int x = -1;

     dis[1] = 0;
     for (int i = 1; i <= n; i++) // running n times
     {
          x = -1;
          for (auto e : edges)
          {
               int u = e.ff;
               int v = e.ss.ff;
               int w = e.ss.ss;
               if (dis[v] > w + dis[u])
               {
                    parent[v] = u;
                    dis[v] = w + dis[u];
                    x = v; // possible cycle
               }
          }
     }
     if (x == -1)
     {
          cout << "NO\n";
     }
     else
     {
          cout << "YES" << endl;

          // backtrack n steps to enter the cycle (get a node guaranteed inside the cycle)
          for (int i = 0; i < n; i++)
               x = parent[x];

          vector<int> cycle;
          int v = x;
          while (true)
          {
               cycle.push_back(v);
               if (v == x && cycle.size() > 1)
                    break;
               v = parent[v];
          }
          reverse(cycle.begin(), cycle.end());

          for (int node : cycle)
               cout << node << " ";
          cout << "\n";

          return;
     }
}