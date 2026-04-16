#include <bits/stdc++.h>
using namespace std;
int longest_subarray_sum_optimal(const vector<long long>& arr, long long k) {
    if (arr.empty()) return 0;

    int left = 0; int right = 0;
    long long sum = arr[0];
    int maxlen = 0;
    int n = arr.size();

    while (right < n) {
        while (left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        if (sum == k) {
            maxlen = max(maxlen, right - left + 1);
        }
        right++;
        if (right < n) sum += arr[right];
    }
    return maxlen;
}
int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longest_subarray_sum_optimal(arr, k);
}
// this is optimal if array has zeros and positives
//tc= o(2n)