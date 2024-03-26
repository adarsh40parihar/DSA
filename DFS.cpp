#include <bits/stdc++.h>
using namespace std;

//simple dfs
int node;
vector<vector<int>> adj;
vector<int> vis;           // initialise all values with 0
void dfs(int node)
{
    vis[node] = 1;
    for (auto ch : adj[node])
    {
        if (!vis[node])
            dfs(ch);
    }
}

//colour dfs
vector<int> colour;         // initialise all values with 0
// 0-white
// 1-grey
// 2-black
void colour_dfs(int node)
{
    colour[node] = 1;
    for (auto ch : adj[node])
    {
        if (colour[ch] == 0)
            dfs(ch);
    }
    colour[node] = 2;
}

// vistime and finishtime;
int timecode = 1;
vector<int> vistime,finishtime;
vector<int> vis;   // initialise all values with 0 
void dfs(int node)
{
    vis[node] = 1;
    vistime[node]=timecode;
    timecode++;
    for (auto ch : adj[node])
    {
        if (!vis[node])
            dfs(ch);
    }
    finishtime[node]=timecode;
    timecode++;
}

int main()
{
    cin >> node;
    int e; // no. of edges;
    cin >> e;
    adj.resize(node);
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph
    }
    //Calling DFS in main()
    for (int i = 0; i < node; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
}
