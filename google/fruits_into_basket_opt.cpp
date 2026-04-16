#include<bits/stdc++.h> //this solution is similar to basket problem but here l are r will be moved together to maintain the size of maxlen if we remove l we move r further . we just remove ehole loop for that.in this way we can reduce time complexity from 2n to n.
using namespace std;
class solution{
    public:
    int totalfruits(vector<int>&fruits, int n){
        int l = 0, r = 0, maxlen = 0;
        unordered_map<int,int>mp;
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size()<=2){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};
int main(){
    int n; cin>>n;
    vector<int> fruits(n);
    for(int i = 0; i<n; i++){
        cin>>fruits[i];
    }
    solution s; 
    int result  = s.totalfruits(fruits, n);
    cout<<result;
    return 0;
}