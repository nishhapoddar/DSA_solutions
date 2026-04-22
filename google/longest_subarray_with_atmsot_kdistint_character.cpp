#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
int findlongestarray(string s, int k){
    int  l = 0, r=0, maxlen = 0; 
    map<char, int>mp;
    while(r<s.length()){
        mp[s[r]]++;
        if(mp.size()>k){
            mp[s[l]]--;
            if(mp[s[l]]==0) mp.erase(s[l]);
            l++;
        }
        if(mp.size()<=k) maxlen = max(maxlen, r-l+1);
        r++;
    }
    return maxlen;
}
};
int main(){
    string s;
    cin>>s;
    int k; cin>>k;
    solution s1; 
    int result = s1.findlongestarray(s, k);
    cout << result << endl;
}