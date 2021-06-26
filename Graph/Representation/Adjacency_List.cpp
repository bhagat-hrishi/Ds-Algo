#include<bits/stdc++.h>

using namespace std;
const int sz = 1e5+7;
vector<int> adj[sz];
vector<int> vis(sz,0);
deque<int> finalPath;


void printGraph()
{
    cout<<"_____Graph_____\n";
    int index=0;
    for(vector<int>x:adj)
    {
        
        if(x.size()!=0)
        {
            cout<<"for "<<index;
            for(int data:x)
                cout<<" --> "<<data;
            cout<<endl;
        }
        index++;
            
    }
}

int main(){
  
  int v,e;
  cin>>v>>e;

//   Graph build
    
    while(e--)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    printGraph();

}



