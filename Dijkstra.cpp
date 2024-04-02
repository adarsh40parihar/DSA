int n;
vector<vector<pii>> adj(n);
vector<bool> vis(n,0);
vi dis(n,1e18);
vi parent(n,-1);
vi path;
void dijkstra(int s){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dis[s]=0;
    pq.push({dis[s],s});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto p:adj[u]){
            int v = p.ss;
            int w = p.ff;
            if(!vis[v]&&dis[u]+1<dis[v]){
                dis[v]=dis[u]+1;
                parent[v]=u;
                pq.push({dis[v],v});
            }
        }
    }
}
void trace(int node){
    if(parent[node]==-1) return;
    path.pb(parent[node]);
    trace(parent[node]);
}
int32_t main(){
    int f;
    path.pb(f);     //f- final destination
    trace(f);
    reverse(all(path));
}
