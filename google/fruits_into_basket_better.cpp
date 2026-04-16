#include<bits/stdc++.h> //tc: o(2n)
using namespace std;
class solution{
    public:
    int totalfruits(vector<int>&fruits, int n){
        int l = 0, r=0, maxlen = 0;
        unordered_map<int,int>mpp;
        while(r<n){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            if(mpp.size()<=2){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};
int main(){
    int n; cin>>n;
    vector<int>fruits(n);
    for(int i = 0; i<n; i++){
        cin>>fruits[i];
    }
    solution s;
    int result = s.totalfruits(fruits, n);
    cout<<result;
    return 0;
}