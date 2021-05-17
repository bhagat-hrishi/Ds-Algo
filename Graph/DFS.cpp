#include <bits/stdc++.h>
using namespace std;
// const int sz = 1e5+7;

// vector<int>adj[sz];
// vector<int>vis(sz,0);

/*
                    Calling for loop for nodes(in worst case we can call for loop for all components)
                         |
Time complexity -  O(V)+O(V)

                    visited array    
                           |
Space complexity - O(V+E)+O(V);
                      |         
                   adj list    
*/

// dfs function
void dfs(int node, vector<int> &vis, vector<int> adj[])
{
    //visiting subtree of current node
    vis[node] = 1;
    cout << node << " --> ";
    for (int child : adj[node])
    {
        // immmediate childs
        if (!vis[child])
        {
            dfs(child, vis, adj);
            //after visiting child subtree
        }
        //after visiting subtree of current node
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> vis(v + 1, 0);
    vector<int> adj[v + 1];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // as graph contain multiple components we should call dfs for all nodes
    for (int i = 1; i <= v; i++)
    {

        if (!vis[i])
        {
            dfs(i, vis, adj);
        }
    }
}