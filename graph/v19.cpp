#include<bits/stdc++.h>
using namespace std;
class solution{
    private:
    bool dfscheck(int node, vector<int> adj[], int vis[], int pathvis[]){
        vis[node] = 1;
        pathvis[node] = 1;
        //traverse for adjacent node
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfscheck(it, adj, vis, pathvis)== true)
                return true;
            }
            // if node has been previously visited
            // but it has to be visited on the same path 
            else if(pathvis[it]){
                return true;
            }
        }
        pathvis[node]= 0;
        return false;

      }
    public:
    bool iscycle(int V , vector<int> adj[]){
        int vis[V]= {0};
        int pathvis[V]= {0};
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfscheck(i, adj, vis, pathvis)==true) return true;
            }
        }
        return false;
    }
};
