class Solution {
public:
    map<int,int> mp;
    /*int getsmallestgreatest(int i, vector<int>&arr){
        int n = arr.size();
        int val = INT_MAX;
        int idx= -1;
        for(int j = i+1; j<n; j++){
            if(arr[j]>=arr[i]){
                if(arr[j]<val){
                    val = arr[j];
                    idx= j;
                }
            }
        }
        return idx;
    }
    int getlargestsmallest(int i, vector<int>&arr){
        int n = arr.size();
        int val = INT_MIN;
        int idx= -1;
        for(int j = i+1; j<n; j++){
            if(arr[j]<=arr[i]){
                if(arr[j]>val){
                    val = arr[j];
                    idx= j;
                }
            }
        }
        return idx;
    }*/
    bool oddcheck(int i , vector<bool>&odd, vector<bool>&even, vector<int>&arr){
        int n = arr.size();
        //int idx = getsmallestgreatest(i, arr);
        auto it = mp.lower_bound(arr[i]);
        if(it == mp.end())
        //no legal jump
        return false;
        else if(even[it->second]){
            return true;
        }
        return false;
    }
     bool evencheck(int i , vector<bool>&odd, vector<bool>&even, vector<int>&arr){
        int n = arr.size();
        //int idx = getlargestsmallest(i, arr);
        auto it = mp.upper_bound(arr[i]);
        if(it != mp.begin()){
           it--;
        }else{
            return false;
        }
        /*if(idx==-1) //no legal jump
        return false;*/
        if(odd[it-> second]){
            return true;
        }
        return false;
    }
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> even(n, false), odd(n,false);
        odd[n-1]= true;
        even[n-1]= true;
        int cnt = 1;
        mp[arr[n-1]]=n-1;
        for(int i = n-2; i >= 0; i--){
            if(oddcheck(i, odd, even, arr)){
                odd[i]=true;
                cnt++;
            }
            if(evencheck(i, odd, even, arr)){
                even[i]=true;
            }
            mp[arr[i]]= i;
   /* int oddNext = getsmallestgreatest(i, arr);
    int evenNext = getlargestsmallest(i, arr);

    if(oddNext != -1 && even[oddNext]) {
        odd[i] = true;
        cnt++;   // only count odd[i]
    }
    if(evenNext != -1 && odd[evenNext]) {
        even[i] = true;
    }
    mp[arr[i]] =i;*/
}

        return cnt;
        
    }
};