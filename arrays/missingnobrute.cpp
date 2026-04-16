#include <bits/stdc++.h>
using namespace std;

int findmissing(vector<int> &arr, int n) {
    for (int i = 1; i <= n; i++) {
        int flag = 0;
        for (int j = 0; j < (int)arr.size(); j++) {
            if (arr[j] == i) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    int result = findmissing(arr, n);
    cout << result;
}
//brute: tc= 0(n*m)