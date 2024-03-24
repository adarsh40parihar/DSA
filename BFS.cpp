#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define ff first
#define ss second

// Single Source:-
int n;
vi dist;
vector<vector<int>> adj; // graph reprentation

void connectde_bfs()
{
    vector<int> vis(n + 1, 0);
    dist.assign(n + 1, -1);
    queue<int> q;
    q.push(0);  // Assuming source_node=0
    vis[0] = 1; // visit the source node
    dist[0] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop(); // remove front element of q
        for (int i = 0; i < (adj[node].size()); i++)
        {                             // visit all neighbours of s
            int child = adj[node][i]; // new child
            if (vis[child] == 0)
            {
                vis[child] = 1;
                dist[child] = dist[node] + 1; // store the dist of child -> dist of parent +1
                q.push(child);                // if child is not visited, push to queue
            }
        }
    }
}

// Multi source BFS:-
int n;
vi dist;
vector<vector<int>> adj;

void bfs(vi source)
{
    vector<int> vis(n + 1, 0);
    dist.assign(n + 1, -1);
    queue<int> q;
    for (auto s : source)
    {
        vis[s] = 1;
        q.push(s);
        dist[s] = 0;
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : adj[node])
        {
            if (vis[child])
                continue;
            vis[child] = 1;
            dist[child] = 1 + dist[node];
            q.push(child);
        }
    }
}

//not connected GRAPH:-
void not_fully_connected_bfs()
{
    vector<vector<int>> g(n + 1);        // take input
    vector<bool> vis(n + 1, 0);
    vector<int> order;
    int components=0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1)
            continue;
        components++;                   //Number of connected components of a graph
        queue<int> q;
        q.push(i);
        vis[i] = 1;

        while (!q.empty())
        {
            int u = q.front();
            order.push_back(u);
            q.pop();
            for (int v : g[u])
            {
                if (vis[v])
                    continue;
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}

//2D BFS
int n, sz;
vvi dist;
map<pii, vector<pii>> adj;
//vvi adj;

void bfs(vector<pair<int,int>> source){
    vvi vis(n+1,vi(sz+1,0));
    dist.assign(n+1,vi(sz+1,-1));
    queue<pii> q;
    for(auto s:source){
        vis[s.ff][s.ss] = 1;
        q.push(s);
        dist[s.ff][s.ss] = 0;
    }
    
    while(!q.empty()){
        pii node = q.front();
        q.pop();
        for(auto child: adj[node]){
            if(vis[child.ff][child.ss]) continue;
            vis[child.ff][child.ss] = 1;
            dist[child.ff][child.ss] = 1 + dist[node.ff][node.ss];
            q.push(child);
        }
    }
}
