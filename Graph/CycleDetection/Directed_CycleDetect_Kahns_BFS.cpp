#include <bits/stdc++.h>
using namespace std;
/*
As topological sort applicable for DAG  (Directed ACYCLIC Graph)
so if we are unable to generate topo sort then
we can say that graph contain cycle 
*/

bool checkCycle(int v, vector<int> adj[])
{
    vector<int> indegree(v, 0);

    for (int node = 0; node < v; node++)
    {
        // calculate indegree for each node
        for (auto adjecentnode : adj[node])
        {
            indegree[adjecentnode]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        // if indegree for node is 0 then push in queue
        if (indegree[i] == 0)
            q.push(i);
    }

    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;

        for (int adjecentnode : adj[node])
        {
            // decrease indegree of adjecent node
            indegree[adjecentnode]--;

            if (indegree[adjecentnode] == 0)
                q.push(adjecentnode);
        }
    }

    //cnt==v means topological sort is possible so graph not contain cycle
    if (cnt == v)
        return false;

    return true;
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
    if (checkCycle(v, adj))
        cout << "\nGraph contain cycle";
    else
        cout << "\nGraph does not contain cycle";
}
