/*
-> Find shortest distance from source node to every other node 
-> shoretest path in undirected graph with unit(1) edge weights

1)Take distance array and mark each node distance as inifinity
2)mark distance of source node as 0 and put inside queu 
*/
#include <bits/stdc++.h>
using namespace std;

void helperBFS(int source, vector<int> adj[], int v)
{
    // for all nodes initial distance assigned to infinity
    vector<int> distance(v, INT_MAX);

    queue<int> q;

    // make distance of source to source as 0
    distance[source] = 0;

    q.push(source);

    while (q.empty() == false)
    {
        int node = q.front();
        q.pop();

        for (auto adjecentnode : adj[node])
        {
            // if distance of current node + 1 is less than current distance of adjecent node
            if (distance[node] + 1 < distance[adjecentnode])
            {
                distance[adjecentnode] = distance[node] + 1;
                q.push(adjecentnode);
            }
        }
    }

    cout << "\nShortest distance from node " << source << endl;
    cout<<"node "<<" "<<"distance "<<endl;
    for (int node = 0; node < v; node++)
    {
        cout <<node<< "      "<< distance[node] << endl;
    }
}

// _______________________ 0 based indexing (nodes start from 0)
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

    int source;
    cin >> source;
    helperBFS(source, adj, v);
}