#include <bits/stdc++.h>
using namespace std;

int longest_subarray_sum_better(const vector<long long> &arr, long long k) {
    map<long long, int> prefix_index;
    long long sum = 0;
    int max_len = 0;

    for (int i = 0; i < (int)arr.size(); i++) {
        sum += arr[i];

        if (sum == k) {
            max_len = max(max_len, i + 1);
        }

        long long rem = sum - k;
        if (prefix_index.find(rem) != prefix_index.end()) {
            int len = i - prefix_index[rem];
            max_len = max(max_len, len);
        }

        // Store first occurrence only for maximum length.
        if (prefix_index.find(sum) == prefix_index.end()) {
            prefix_index[sum] = i;
        }
    }

    return max_len;
}

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longest_subarray_sum_better(arr, k);
}
//optimal only if the array contians positive and negatives
//tc= o(n*logn) for odered map and for unordered map o(n*1) but in worst it can go to o(n*n)