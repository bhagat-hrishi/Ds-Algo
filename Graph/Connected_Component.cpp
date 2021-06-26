#include<bits/stdc++.h>
using namespace std;


void dfs(int node,vector<int>&vis,vector<int>adj[]){
    cout<<node<<" --> ";
    vis[node]=1;
    for(int child:adj[node]){
        if(vis[child]==0)//if node is not visited then call dfs
            dfs(child,vis,adj);
    }
}

// ___________________ node start from 0 ___________________
int main()
{
    int v,e;
    cin>>v>>e;

    vector<int>vis(v,0);
    vector<int>adj[v];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cocompCount=0;

// To call for all components 
    for(int i=0;i<v;i++)
    {
        if(vis[i]==0)
        {
            dfs(i,vis,adj);
            cout<<endl;
            cocompCount++;
        }
    }

    cout<<"\nTotal connected components: "<<cocompCount<<endl;
  
    return 0;
}