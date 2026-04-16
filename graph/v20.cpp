#include<bits/stdc++.h>
using namespace std;
class solution{
    private:
    bool dfscheck(int node, vector<int> adj[], int vis[], int pathvis[],int check[]){
        vis[node]= 1;
        pathvis[node]= 1;
        check[node]= 0; 
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfscheck(it, adj, vis, pathvis, check)== true){
                    check[node]= 0;
                    return true;
                }
            }
            else if(pathvis[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathvis[node] = 0;
        return false;
    }
public:
vector<int> eventualsafenodes(int V, vector<int> adj[]){
    int vis[V]= {0};
    int pathvis[V]= {0};
    int check[V] = {0};
    vector<int> safenodes;

    for(int i = 0; i<V; i++){
        if(!vis[i]){
            dfscheck(i, adj, vis, pathvis, check);
        }
    }

    for(int i = 0; i<V; i++){
        if(check[i]==1) safenodes.push_back(i);
    }
    return safenodes;
}
};