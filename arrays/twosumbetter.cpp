#include<bits/stdc++.h>
using namespace std;

pair<int, int> twosum(vector<int> &arr, int n, int target){
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        int current = arr[i];
        int remaining = target - current;
        if(mp.find(remaining) != mp.end()){
            return {mp[remaining], i};
        }
        mp[current] = i;
    }
    return {-1, -1};
}

int main(){
    int n; cin>>n; vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int target; cin>>target;
    pair<int, int> result = twosum(arr, n, target);
    cout << result.first << " " << result.second;

    return 0;
}