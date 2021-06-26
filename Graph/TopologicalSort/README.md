# Topological Sort
- Topological sorting for `Directed Acyclic Graph (DAG)` is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering

- Every DAG may have one or more topological orderings.
- `If a Hamiltonian path exists, the topological sort order is unique.`
- BFS 
    - Algo
    1. calculate indegree for all nodes
    2. push elements with indegree 0 inside queue
    3. pop element and add in topo sort and decrease indegree for adjcent nodes
    4. if indegree of any of adjcent node is 0 push inside queue and repeat process from 2 
  until queue is empty
- Application 
    - Representing course prerequisites
    - Detecting deadlocks
    - Pipeline of computing jobs
    - Checking for symbolic link loop
    - Evaluating formulae in spreadsheet
