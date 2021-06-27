/*
find paret => gives parent of component
Union => It will combine component

Union By rank and Path compression
1)at start
    every node is parent of itselft
    initial rank of all elements is 0

Union 
1)If both rank is same 
    then to the guy whome we are attaching its rank should increase by one 
2)If both rank are different
    smaller rank is attached to larger one

Time complexity of Both FindParent() and Union() is O(4*alpha)

*/

#include <bits/stdc++.h>
using namespace std;

int findPar(int node, vector<int> &parent)
{
    if (node == parent[node]) //if node is parent of itself
    {
        return node;
    }

    // parent[node] =>This will do path compression
    return parent[node] = findPar(parent[node], parent);
}

void Union(int u, int v, vector<int> &rank, vector<int> &parent)
{
    u = findPar(u, parent); //get parent of u
    v = findPar(v, parent); //get parent of v

    // smaller node rank is attached to node which has more rank
    if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    // if both have same rank any node can attach to any and just increase rank of node to whom we are attaching
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

// _____________ 1 based indexing (node start from 1)
int main()
{
    int v;
    cin >> v;

    // if n nodes then for all nodes it set rank of each as 0 and everyonce parent is himself
    vector<int> parent(v + 1);
    vector<int> rank(v + 1, 0); //initially rank of all nodes is 0
    // initially assign parent of node as node itselft
    for (int i = 1; i < v + 1; i++)
    {
        parent[i] = i;
    }
    int unioncnt;
    cin >> unioncnt;

    while (unioncnt--)
    {
        int x, y;
        cin >> x >> y;
        Union(x, y, rank, parent);
    }
    int x, y;
    cin >> x >> y;
    if (findPar(x, parent) != findPar(y, parent))
    {
        cout << x << " & " << y << " Belong to Different component" << endl;
    }
    else
    {
        cout << x << " & " << y << " Belong to same component" << endl;
    }
}

/*
7 ->totla cnt
4 -> union cnt 
1 2 
2 3
4 5
6 7
1 7 -> no to check
*/