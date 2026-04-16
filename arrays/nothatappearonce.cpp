#include <bits/stdc++.h>
using namespace std;

int find_number_that_appears_once(vector<int> &arr, int n) {
    int maxi = arr[0];
    for (int i = 0; i < n; i++) {
        maxi = max(arr[i], maxi);
    }

    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1)
            return arr[i];
    }
    return -1;
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
// better: tc= 0{3n}, sc= o(maxi)
//cant be used for bigger numbers