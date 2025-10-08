#include <bits/stdc++.h>
using namespace std;

class Prim
{
public:
    int n;
    vector<vector<pair<int, int>>> adj;

    Prim(int N)
    {
        n = N;
        adj.resize(n + 1);
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int mst(int start = 1)
    {
        vector<int> dist(n + 1, INT_MAX), vis(n + 1, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[start] = 0;
        pq.push({0, start});
        int cost = 0;

        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            cost += w;

            for (auto [v, wt] : adj[u])
            {
                if (!vis[v] && wt < dist[v])
                {
                    dist[v] = wt;
                    pq.push({wt, v});
                }
            }
        }

        for (int i = 1; i <= n; i++)
            if (!vis[i])
                return -1; // disconnected
        return cost;
    }
};

class DSU
{
public:
    vector<int> p, sz;

    DSU(int n)
    {
        p.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            p[i] = i;
    }

    int find(int x)
    {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

class Kruskal
{
public:
    int n;
    vector<tuple<int, int, int>> edges;

    Kruskal(int N)
    {
        n = N;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, u, v});
    }

    int mst()
    {
        sort(edges.begin(), edges.end());
        DSU dsu(n);
        int cost = 0, cnt = 0;

        for (auto [w, u, v] : edges)
        {
            if (dsu.unite(u, v))
            {
                cost += w;
                cnt++;
            }
        }

        if (cnt != n - 1)
            return -1; // disconnected
        return cost;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    Prim prim(n);
    Kruskal kr(n);

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        prim.addEdge(u, v, w);
        kr.addEdge(u, v, w);
    }

    cout << "Prim MST: " << prim.mst() << "\n";
    cout << "Kruskal MST: " << kr.mst() << "\n";
    return 0;
}
