#include <bits/stdc++.h>
using namespace std;
/*
Algo
1)calculate indegree for all nodes
2)push elements with indegree 0 inside queue
3)pop element and add in topo sort and decrease indegree for adjcent nodes
4)if indegree of any of adjcent node is 0 push inside queue and repeat process from 2 
  until queue is empty

time complexity of O(V + E) 
    – where V is the number of vertices  and E is the number of edges in the graph.



*/

vector<int> TopoSortWithBFS(int v, vector<int> adj[])
{
    queue<int> q;

    // create indegree array with value 0 for all nodes
    vector<int> indegree(v, 0);

    // calculating indegree for all nodes
    for (int i = 0; i < v; i++)
    {
        for (auto adjecentnode : adj[i])
        {
            indegree[adjecentnode]++;
        }
    }

    for (int i = 0; i < v; i++)
    {
        // if node has indegree as 0 push inside queue (i.e. those nodes does not have any dependency)
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto adjecentnode : adj[node])
        {
            // decrease indegree of adjecent nodes
            indegree[adjecentnode]--;

            //now if indegree of node is 0 (means it does not have any dependecy so push inside queue)
            if (indegree[adjecentnode] == 0)
            {
                q.push(adjecentnode);
            }
        }
    }

    return topo;
}
// _____________considering graph 0 base indexing (start with 0)__________
int main()
{
    int v, e;
    cin >> v >> e;

    vector<int> adj[v];
    for (int i = 0; i < v; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<int> toposort = TopoSortWithBFS(v, adj);

    for (int node : toposort)
        cout << node << " ";
}
