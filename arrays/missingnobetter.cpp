#include <bits/stdc++.h>
using namespace std;

int findmissing(vector<int> &arr, int n) {
    vector<int> hash(n + 1, 0);
    for (int i = 0; i < arr.size(); i++) {
        hash[arr[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0)
            return i;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> arr[i];

    int result = findmissing(arr, n);
    cout << result;
}
// better : tc = 0(n)+ 0(M); sc = 0(n)