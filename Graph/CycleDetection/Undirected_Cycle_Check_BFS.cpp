#include <bits/stdc++.h>
using namespace std;

bool helperFunction(int source, vector<int> &vis, vector<int> adj[])
{
    // mark node as visited
    vis[source] = 1;

    // queue<pair<node,parent>>
    queue<pair<int, int>> q;
    q.push({source, -1}); //initial at start parent is -1

    while (!q.empty())
    {
        auto it = q.front();
        int source = it.first;
        int parent = it.second;
        q.pop();

        // now visit adjecent nodes  of source
        for (int child : adj[source])
        {
            if (vis[child]==0)//if not visited
            {
                // push unvisited node and its parent inside queue
                q.push({child, source});
                // make node visited
                vis[child] = 1;
            }
            else if (child != parent)
            {
                // if  node is visited allready and it is not parent then return true
                return true;
            }
        }
    }
    return false;
}
bool detectCycle(int &v, vector<int> &vis, vector<int> adj[])
{
    for (int i = 1; i < v + 1; i++)
    {
        if (!vis[i])
        {
            if (helperFunction(i, vis, adj))
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

    vector<int> vis(v + 1, 0);
    vector<int> adj[v + 1];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (detectCycle(v, vis, adj))
        cout << endl
             << "Cycle present inside graph";
    else
        cout << endl
             << "Cycle not present";
}