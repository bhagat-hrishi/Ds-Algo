#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int source, int parent, vector<int> &vis, vector<int> adj[])
{
    // make node visited 
    vis[source] = 1;

    for (auto child : adj[source])//traverse adjecent nodes
    {
        if (vis[child] == 0)//if not visited
        {
            if (checkForCycle(child, source, vis, adj))
                return true;
        }
        else if (child != parent)//if node is visited and not a parent 
            return true;
    }

    return false;
}
bool detectCycle(int &v, vector<int> &vis, vector<int> adj[])
{
    for (int i = 1; i < v + 1; i++)
    {
        if (!vis[i])
        {

            if (checkForCycle(i, -1, vis, adj))//for init node parent is -1
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