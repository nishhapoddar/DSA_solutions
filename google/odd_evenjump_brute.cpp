#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getsmallestgreatest(int i, vector<int>&arr){
        int n = arr.size();
        int val = INT_MAX;
        int idx= -1;
        for(int j = i+1; j<n; j++){
            if(arr[j]>=arr[i]){
                if(arr[j]<val){
                    val = arr[j];
                    idx= j;
                }
            }
        }
        return idx;
    }
    int getlargestsmallest(int i, vector<int>&arr){
        int n = arr.size();
        int val = INT_MIN;
        int idx= -1;
        for(int j = i+1; j<n; j++){
            if(arr[j]<=arr[i]){
                if(arr[j]>val){
                    val = arr[j];
                    idx= j;
                }
            }
        }
        return idx;
    }
    bool oddcheck(int i , vector<bool>&odd, vector<bool>&even, vector<int>&arr){
        int n = arr.size();
        int idx = getsmallestgreatest(i, arr);
        if(idx==-1) //no legal jump
        return false;
        else if(even[idx]){
            return true;
        }
        return false;
    }
      bool evencheck(int i , vector<bool>&odd, vector<bool>&even, vector<int>&arr){
        int n = arr.size();
        int idx = getlargestsmallest(i, arr);
        if(idx==-1) //no legal jump
        return false;
        else if(odd[idx]){
            return true;
        }
        return false;
    }
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return 0;
        vector<bool> even(n, false), odd(n,false);
        odd[n-1]= true;
        even[n-1]= true;
        int cnt = 1;
        for(int i = n-2; i >= 0; i--){
    int oddNext = getsmallestgreatest(i, arr);
    int evenNext = getlargestsmallest(i, arr);

    if(oddNext != -1 && even[oddNext]) {
        odd[i] = true;
        cnt++;   // only count odd[i]
    }
    if(evenNext != -1 && odd[evenNext]) {
        even[i] = true;
    }
}

        return cnt;
        
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Solution s;
    cout << s.oddEvenJumps(arr);
    return 0;
}