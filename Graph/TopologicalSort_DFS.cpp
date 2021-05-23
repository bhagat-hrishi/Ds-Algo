#include <bits/stdc++.h>
using namespace std;
/*
    Time complexity ->  O(n+e)

                visited array
                         |
    Space complexity -> O(n)

    auxilary space complexity - O(n) [For using stack]
*/
void helperDFS(int node, vector<int> &vis, vector<int> adj[], stack<int> &s)
{
    // make node as visited
    vis[node] = 1;

    // call helperDFS for not visited child nodes
    for (auto child : adj[node])
    {
        if (vis[child] == 0)
            helperDFS(child, vis, adj, s);
    }

    // after completing DFS call push node inside stack
    s.push(node);
}
vector<int> topoSort(int v, vector<int> adj[])
{
    // visited array
    vector<int> vis(v, 0);

    vector<int> topo;

    stack<int> s;

    // As graph contain multiple components call dfs helper for all components
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
            helperDFS(i, vis, adj, s);
    }

    while (!s.empty())
    {
        topo.push_back(s.top());
        s.pop();
    }

    return topo;
}

// ___________________ 0 based indexing __________________
int main()
{
    int v, e;
    cin >> v >> e;

    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<int> topo = topoSort(v, adj);

    cout << "\nTopo Sort: ";
    for (auto data : topo)
    {
        cout << data << " ";
    }
    cout << endl;
}