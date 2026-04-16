#include<bits/stdc++.h>
using namespace std;
vector<int> intersectionarray(vector<int> &a, vector<int> &b){
    int n1= a.size();
    int n2= b.size();
    vector<int> vis(n2,0);
    vector<int> ans;
    for(int i = 0; i<n1; i++){
        for(int j = 0; j<n2; j++){
            if(a[i]==b[j] && vis[j]==0){
            ans.push_back(a[i]);
            vis[j]=1;
            break;
            }
            if(b[j]>a[i]) //as array is sorted
            break;
            
        }
    }
    return ans;
}
int main(){
    int n1;
    cin>>n1;
    vector<int> a(n1);
    for(int i = 0; i<n1; i++){
        cin>>a[i];
    }
    int n2;
    cin>>n2;
    vector<int> b(n2);
    for(int i = 0; i<n2; i++){
        cin>>b[i];
    }
    vector<int> result = intersectionarray(a,b);
    for(int x: result){
        cout<<x<<" ";
    }
}
//tc=0(n1*n2) , sc=0(size of smaller array)
//not an optimal solution
