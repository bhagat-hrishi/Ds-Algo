/*
Shoretest path from  source to every other node using Dijkstra's Algo
-> edge weights are different 

1)take min heap with {distance , node }
2)Distance array equal to no of nodes and mark all intial value as infinity
*/
#include <bits/stdc++.h>
using namespace std;

// _____________________  node start from 1
int main()
{
    int v, e;
    cin >> v >> e;

    // {node}
    vector<pair<int, int>> adj[v + 1];

    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int source;
    cin >> source;

    // Algo begin here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap {distace , node}

    vector<int> dist(v + 1, INT_MAX); //distance array init to infinity

    dist[source] = 0; //distance of source from itself it 0

    // {distance,node}
    pq.push({0, source});

    while (pq.empty() == false)
    {
        int predist = pq.top().first;//distance
        int pre = pq.top().second;//node
        

        pq.pop();


        for(auto it:adj[pre])
        {
            int nextnode=it.first;
            int nextdist=it.second;

            if(dist[nextnode]> predist + nextdist)
            {
                dist[nextnode] = predist + nextdist;
                pq.push({dist[nextnode],nextnode});
            }
        }
    }

    cout <<"\nShortest distance from node " << source << endl;
    cout<<"node "<<" "<<"distance "<<endl;
    for (int node = 1; node <v+1; node++)
    {
        cout <<node<< "      "<< dist[node] << endl;
    }
}