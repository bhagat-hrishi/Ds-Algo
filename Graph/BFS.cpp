#include <bits/stdc++.h>
using namespace std;
/*
Algo - 
1)Run loop for all nodes as graph contain multiple components
2)insert node inside queue and mark that node as visited
3)iterate until queue is not empty
*/

/*
Time complexity -  O(V+E) (in worst case we visit all nodes in bfs travesal)

                        For queue(in worst case all n-1 node connected to one node)
                            |
Space complexity - O(V+E)+O(V)+O(V);
                                |
                            visited array
*/



int main()
{
    int v,e;
    cin>>v>>e;
    
    cout<<"v : "<<v<<" e: "<<e<<endl;
    vector<int>adj[v+1];
    vector<int>vis(v+1,0);
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int>bfstraversal;
    // As graph contain multiple components we should run loop for every node
    for(int i=0;i<=v;i++)
    {
        // if node is not visited push inside queue and mark as visited
        if(!vis[i])
        {
            queue<int>q;
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                bfstraversal.push_back(node);
                
                // now if adjecent nodes not visited mark as visited & push inside queue
                for(auto data:adj[node])
                {
                    if(!vis[data])
                    {
                        vis[data]=1;
                        q.push(data);
                    }
                }
            }
        }
    }

    for(auto data:bfstraversal)
        cout<<data<<" ";

}