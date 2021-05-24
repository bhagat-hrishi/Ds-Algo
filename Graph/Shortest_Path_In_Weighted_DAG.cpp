// Shortest path in weighted directed acyclic graph
#include <bits/stdc++.h>
using namespace std;
/*
1)Find topological sort for DAG


time complexity - O(n+e)*2
space complexity - O(2*n)
*/

void findTopoSort(int node, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &st)
{
    // make node as visited
    vis[node] = 1;

    // call toposort for adjecent nodes
    for (auto adjecentnode : adj[node])
    {
        if (vis[adjecentnode.first] == 0)
            findTopoSort(adjecentnode.first, vis, adj, st);
    }
    // after completing dfs push inside stack
    st.push(node);
}
void shortestPath(int source, int v, vector<pair<int, int>> adj[])
{
    // create visited array
    vector<int> vis(v, 0);

    stack<int> st;

    // find topo sort
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
            findTopoSort(i, vis, adj, st);
    }

    // create distance array mark all as infinity
    int distace[v];
    for (int i = 0; i < v; i++)
        distace[i] = INT_MAX;

    const int INF = INT_MAX;
    // make distance of source as 0
    distace[source] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        // if that node has been reached previously
        if (distace[node] != INF)
        {
            for (auto it : adj[node])
            {

                if (distace[node] + it.second < distace[it.first])
                {
                    distace[it.first] = distace[node] + it.second;
                }
            }
        }
    }

    cout<<"Shortest Distance from "<<source <<" to "<<endl;
    for (int i = 0; i < v; i++)
    {
        cout<<" node "<<i<<" is ";
        (distace[i] == INF) ? cout <<"INF "<<endl : cout << distace[i] <<endl;
    }
}
int main()
{
    int v, e;
    cin >> v >> e;

    //  pair<nodevalue,weight>
    vector<pair<int, int>> adj[v];
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        // pushing node and weight to go from x to y
        adj[x].push_back({y, w});
    }

    // call shortestpath function with source node , no of vertices and adjecency list
    shortestPath(0, v, adj);
}