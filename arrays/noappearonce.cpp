#include <bits/stdc++.h>
using namespace std;

int find_number_that_appears_once(vector<int> &arr, int n) {
   map<long, long> mp;
   for(int i = 0; i<n; i++){
    mp[arr[i]]++;
   }
   for(auto it: mp)
   if(it.second == 1)
   return it.first;

}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = find_number_that_appears_once(arr, n);
    cout << result;
}
// optimal solution : tc= 0(n/2+1) + 0(nlogm), sc= o(n/2+1)