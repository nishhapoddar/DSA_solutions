#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Check if the current digit is already the highest valid value at index i.
    bool isAlreadyHighest(int i, int v, const vector<int>& a) {
        return (i == 3 && v == 9) ||
               (i == 2 && v == 5) ||
               (i == 1 && v == 3 && a[0] == 2) ||
               (i == 0 && v == 2);
    }

    // Check if placing value v at index i would make time invalid.
    bool isInvalid(int i, int v, const vector<int>& a) {
        return (i == 2 && v > 5) ||
               (i == 1 && v > 3 && a[0] == 2) ||
               (i == 0 && v > 2);
    }

    string nextClosestTime(const string& time) {
        set<int> sortedTree;
        vector<int> intValues(4);

        int y = 0;
        for (char c : time) {
            if (c != ':') {
                int x = c - '0';
                sortedTree.insert(x);
                intValues[y++] = x;
            }
        }

        for (int i = 3; i >= 0; --i) {
            auto it = sortedTree.upper_bound(intValues[i]);
            int higher = (it == sortedTree.end()) ? -1 : *it;

            if (higher == -1 ||
                isAlreadyHighest(i, intValues[i], intValues) ||
                isInvalid(i, higher, intValues)) {
                intValues[i] = *sortedTree.begin();
            } else {
                intValues[i] = higher;
                break;
            }
        }

        string result;
        for (int i = 0; i < 4; ++i) {
            result += char(intValues[i] + '0');
            if (i == 1) result += ':';
        }
        return result;
    }
};

int main() {
    string time;
    cin >> time;

    Solution s;
    cout << s.nextClosestTime(time) << '\n';
    return 0;
}