// Binary Lifting

int x=log2(n)+1; //max possible jump req to reach 
// a parent (You can also take x=30)

vector<vector<int> > v; // adjacency list of tree
int par[n][x]; 
// IMP : par[i][j] = 2^(j)th parent of ith node
// store 2^1,2^2 parents of node s 

void dfs(int s,int p)
{
// s-->source node
// p-->parent of s..
  par[s][0]=p;
  for(int j=1;j<x;j++)
    par[s][j]=par[par[s][j-1]][j-1];
  for(int i=0;i<v[s].size();i++)
  {
     int ch=v[s][i];
     if(ch!=p)
      dfs(ch,s)
  }
}

// k-->jump-->binary representation

int find_kth(int s,int k)
{
 for(int j=x-1;j>=0;j--)
 {
    if((1<<j)&k)//jth bit set or not in k..
    {
      s=par[s][j];//jump of 2^j
    }
return s;
}

//Time complexity: O(log n) per query




#include <bits/stdc++.h>
using namespace std;

int n;
int Log;

vector<vector<int>> adj;
vector<vector<int>> par;
vector<int> depth;

/*
par[node][j]
= 2^j th ancestor of node

Example:
par[node][0] -> parent
par[node][1] -> grandparent (2^1)
par[node][2] -> 4th ancestor (2^2)
...
*/

void dfs(int u, int p)
{
    par[u][0] = p;
    // Precompute all 2^j ancestors
    for(int j = 1; j < Log; j++)
    {
        if(par[u][j - 1] != -1)
            par[u][j] = par[par[u][j - 1]][j - 1];
        else
            par[u][j] = -1;
    }
    for(auto v : adj[u])
    {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int find_kth(int s, int k)
{
    for(int j = Log - 1; j >= 0; j--)
    {
        if(s == -1) break;
        if(k & (1 << j))
            s = par[s][j];
    }
    return s;
}

/*
Lowest Common Ancestor

Steps:
1. Bring deeper node to same depth.
2. If equal => answer found.
3. Lift both simultaneously.
4. Parent of either node is LCA.
*/
int find_lca(int u, int v)
{
    // Make u the deeper node
    if(depth[u] < depth[v])
        swap(u, v);

    // Bring u to same depth as v
    int diff = depth[u] - depth[v];
    u = find_kth(u, diff);

    // One node is ancestor of other
    if(u == v) return u;
  
    // Lift both nodes together
    for(int j = Log - 1; j >= 0; j--)
    {
        if(par[u][j] != par[v][j])
        {
            u = par[u][j];
            v = par[v][j];
        }
    }
    // Parent is the LCA
    return par[u][0];
}


int main()
{
    cin >> n;
    adj.resize(n + 1);
    // Input n-1 edges its a tree
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Log = log2(n) + 1;

    par.assign(n + 1, vector<int>(Log, -1));
    depth.assign(n + 1, 0);

    // Root tree at node 1
    dfs(1, -1);

    int q;
    cin >> q;

    while(q--)
    {
        int u, v;
        cin >> u >> v;
        cout << "LCA = " << find_lca(u, v) << "\n";
    }
    return 0;
}

/*
Complexities:
Preprocessing: O(N log N)
find_kth(): O(log N)
find_lca(): O(log N)
*/

