#include<bits/stdc++.h>
void dfs(unordered_map<int, list<int>>&adj, vector<bool>&vis, stack<int>&ordereds, int node){
    vis[node]=1;
    for(auto neighbour:adj[node]){
        if(!vis[neighbour])
            dfs(adj, vis, ordereds, neighbour);
            
    }
    ordereds.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int, list<int>>adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
    }
    vector<bool>vis(v);
    vector<int>toposort;
    stack<int>ordereds;
    for(int i=0;i<v;i++){
        if(!vis[i])
   { dfs(adj, vis, ordereds, i);}
        
    }
    while(!ordereds.empty()){
        toposort.push_back(ordereds.top());
        ordereds.pop();
    }
    return toposort;
}
