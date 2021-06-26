
/*
Used to find strongly connected component in directed graph 


Algo - 
1)Sort all nodes in order of finishing time -> use topo sort      => take O(n)
2)Transpose the graph (So that we are not going to end up another part)   => take O(n+e)
        -> reverse edges
        -> Advantage of this is we will not go to another strongly connected component
3)Do DFS according to finishing time   =>  take O(n+e)

Total Time complexity => O(n+e)

                To store transpose of graph 
                        |
Space complexity ==> O(n+e) + O(n) + O(n)
                                |     |
                                |   To store Stack
                                |
                        To store visited array 

*/

#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (vis[child] == 0)
            topoSort(child, adj, vis, st);
    }
    st.push(node);
}

void revDFS(int node, vector<int> &vis, vector<int> transpose[])
{
    vis[node] = 1; //mark node as visited
    cout << node << " ";

    for (auto it : transpose[node])
    {
        if (vis[it] == 0) //if node is not visited then only call
        {
            revDFS(it, vis, transpose);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<int> adj[v];

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); //directed graph
    }

    stack<int> st;
    vector<int> vis(v, 0);

    // step 1 -> call dfs(toposort)
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
            topoSort(i, adj, vis, st); //call toposort
    }

    // step 2 -> make transpose of graph
    vector<int> transpose[v];

    for (int i = 0; i < v; i++)
    {
        vis[i] = 0; //in previous topo call we visited now mark as unvisited
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    // step 3 ->
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (vis[node] == 0) //if node is not visited
        {
            cout << "SCC: ";
            revDFS(node, vis, transpose);
            cout << endl;
        }
    }
}