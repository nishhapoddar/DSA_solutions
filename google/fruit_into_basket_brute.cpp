#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int totalfruits(vector<int> &fruits){
        int maxlen = 0;
        int n = fruits.size();
        for(int i = 0; i<n; i++){
            set<int> st;
            for(int j = i; j<n; j++){
                st.insert(fruits[j]);
                if(st.size() <= 2){
                    maxlen = max(maxlen, j-i+1);
                }
                else
                break;
            
            }
        }
        return maxlen;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>fruits(n);
    for(int i = 0; i<n; i++){
        cin>>fruits[i];
    }
    solution sol;
    int result = sol.totalfruits(fruits);
    cout<<result;
}