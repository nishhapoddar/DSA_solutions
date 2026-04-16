#include<bits/stdc++.h>
using namespace std;
bool twosum(vector<int>&arr, int  n, int target){
    int left = 0; int right = n-1;
    sort(arr.begin(), arr.end());
    while(left<right){
        int sum = arr[left]+ arr[right];
        if(sum== target){ return true;}
        else if(sum>target) right--;
        else left++;
    }
    return false;
}
int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    int target; cin>>target;
    bool result = twosum(arr, n, target);
    cout << (result ? "YES" : "NO");
    return 0;

}