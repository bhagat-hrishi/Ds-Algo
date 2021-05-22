#include <bits/stdc++.h>
using namespace std;

// __________________ O based indexing (start node is 0) ________________

bool helperDFS(int node, int parent, vector<int> &vis, vector<int> adj[])
{
    // mark node as visited
    vis[node] = 1;

    // call dfs for adjecent nodes
    for (int adjecentnode : adj[node])
    {
        if (vis[adjecentnode] == 0)
        {
            if (helperDFS(adjecentnode, node, vis, adj))
                return true;
        }
        /*
        else if adjcenent node is visited and adjecent node is not equal to parent of current node
        */
        else if (adjecentnode != parent)
            return true;
    }
    return false;
}
bool isCycle(int v, vector<int> adj[])
{
    vector<int> vis(v, 0);
    //as graph contian multipe components so visit all components
    for (int i = 0; i < v; i++)
    {
        
        // initial parent for node is -1
        if (helperDFS(i, -1, vis, adj) == true)  //if any one component find cycle then we return true
            return true;
    }
    return false;
}
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
        adj[y].push_back(x);
    }

    if (isCycle(v, adj))
        cout << "Cycle present\n";
    else
        cout << "Cycle not present\n";
}