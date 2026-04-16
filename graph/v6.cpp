#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& ls){
        vis[node] = 1;
        ls.push_back(node);
        // Traverse all neighbors.
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, ls);
            }
        }
    }
    public:
    vector<int> dfsOfGraph(int v, vector<int> adj[]){
        vector<int> vis(v, 0);
        vector<int> ls;
        int start = 0;
        dfs(start, adj, vis, ls);
        return ls;
    }

};

int main(){
    int v, m;
    cin >> v >> m;

    vector<int> adj[v];
    for(int i = 0; i < m; i++){
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    Solution obj;
    vector<int> ans = obj.dfsOfGraph(v, adj);
    for(int node : ans){
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}