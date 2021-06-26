/*
Shortes Path from source to all other vertex with negative edge
If graph contin negative edge cycle then this will algo "not work"

Algo :
    Relax all edges n-1 times
    i.e.
    if(dist[u]+wt < dist[v])
        dist[v]=dist[u]+wt

After relaxation for n-1 times whatever distance we have it is shortest 

How to check for -ve cycle
if we relax nth time then distance decrease from that we can say there is -ve cycle present

Time complexity => O(n-1)*O(e)
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

// _______________ 0 base indexing (node start from 0)
int main()
{
    int v, e;
    cin >> v >> e;

    vector<node> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back(node(u, v, wt));
    }

    int source;
    cin >> source;

    // Algo start 
    
    int inf = 10000000;
    vector<int> dist(v, inf); //declare distance array with infinity

    dist[source]=0;//mark distance of source as 0 from source
    
    for (int i = 1; i <=v-1; i++)// relax edges n-1 times
    {
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;

            }
        }
    }

    int flag = 0;
    // do relaxation one more time and if distance is still reducing then we can say graph has -ve cycle
    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            cout << "\nGraph contain negative cycle";
            flag = 1;
            break;
        }
    }

// flag still 0 means no cycle present 
    if (flag == 0)
    {
        cout <<"\nShortest distance from node " << source << endl;
        cout<<"node "<<" "<<" distance "<<endl;
        for (int i = 0; i < v; i++)
        {
            cout <<i<<"       "<< dist[i] << endl;
        }   
    }

    return 0;
}

/* 
6 7 
3 2 6 
5 3 1 
0 1 5 
1 5 -3 
1 2 -2 
3 4 -2 
2 4 3 
0
*/