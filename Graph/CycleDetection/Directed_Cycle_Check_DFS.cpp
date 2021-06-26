#include <bits/stdc++.h>
using namespace std;
/*
take 2 visited array
1)visited array
2)DFS visited array  
    -> while going back from dfs visited mark node as unvisited 

if node is visited in both vis array and current Dfs vis array

Time complexity --> O(n+e)
Space complexity --> O(2*n)
*/

bool checkForCycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis)
{
    vis[node] = 1;    //make node as visited
    dfsVis[node] = 1; //mark dfs of visited array as 1

    for (auto it : adj[node])
    {
        if (vis[it] == 0) //if adjecent node is not visited
        {
            if (checkForCycle(it, adj, vis, dfsVis))
                return true;
        }
        else if (dfsVis[it] == true)
            return true;
    }
    dfsVis[node] = 0;
    return false;
}
bool detectCycle(int &v, vector<int> adj[])
{
    vector<int> vis(v + 1, 0);
    vector<int> dfsVis(v + 1, 0);
    for (int i = 1; i < v + 1; i++)
    {
        if (!vis[i])
        {

            if (checkForCycle(i, adj, vis, dfsVis))
                return true;
        }
    }
    return false;
}

// __________________ node start from 1 _______________
int main()
{
    int v, e;
    cin >> v >> e;

    vector<int> adj[v + 1];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    if (detectCycle(v, adj))
        cout << endl
             << "Cycle present inside graph";
    else
        cout << endl
             << "Cycle not present";
}