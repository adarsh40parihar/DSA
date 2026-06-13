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




// LCA
#include <bits/stdc++.h>
using namespace std;

const int N = 200005;      // Maximum number of nodes
const int LOG = 20;        // log2(N)

vector<int> tree[N];
int up[N][LOG];            // up[v][j] = 2^j-th ancestor of v
int depth[N];

/*
    DFS to:
    1. Calculate depth of each node
    2. Fill binary lifting table
*/
void dfs(int node, int parent) {
    up[node][0] = parent;

    // Fill ancestors at powers of 2
    for (int j = 1; j < LOG; j++) {
        up[node][j] = up[up[node][j - 1]][j - 1];
    }

    for (int child : tree[node]) {
        if (child == parent) continue;

        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}

/*
    Returns Lowest Common Ancestor of u and v
*/
int lca(int u, int v) {

    // Ensure u is deeper
    if (depth[u] < depth[v])
        swap(u, v);

    // Lift u to same depth as v
    int diff = depth[u] - depth[v];

    for (int j = LOG - 1; j >= 0; j--) {
        if (diff & (1 << j))
            u = up[u][j];
    }

    // If both become same node
    if (u == v)
        return u;

    // Lift both together until parents differ
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }

    // Parent of either is the LCA
    return up[u][0];
}

int main() {
    int n;
    cin >> n;

    // Input n-1 edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int root = 1;

    depth[root] = 0;
    dfs(root, root);

    int q;
    cin >> q;

    while (q--) {
        int u, v;
        cin >> u >> v;

        cout << lca(u, v) << "\n";
    }

    return 0;
}
