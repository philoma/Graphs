#include<bits/stdc++.h>
bool iscyclic(unordered_map<int, list<int>>&adj, unordered_map<int,bool>&vis, int node){
   
    unordered_map<int, int>parent;
    
    parent[node]=-1;
    queue<int>q;
    q.push(node);
    vis[node]=1;
    
    while(!q.empty()){
        
        int front=q.front();
        q.pop();
        //sab neighbours nikal liye:
        for(auto neighbour: adj[front]){
            if(vis[neighbour]==true && neighbour!=parent[front]){
                return true;
            }else if(!vis[neighbour]){
                q.push(neighbour);
                vis[neighbour]=1;
                parent[neighbour]=front;
            }
        }
        
        
        
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int,bool>vis;
    //to hadndle disconnected component
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
           bool ans= iscyclic(adj,vis, i);
            if(ans==1)
                return "Yes";
        }
        
    }
    return "No";
        
}
//link: https://takeuforward.org/data-structure/detect-a-cycle-in-undirected-graph-breadth-first-search/
