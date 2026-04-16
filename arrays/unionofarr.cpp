#include<bits/stdc++.h>
using namespace std;
vector<int> findunion(vector<int>&arr1, vector<int>&arr2){
    int i = 0; int j = 0;
    vector<int> uni;
    while(i<arr1.size() && j<arr2.size()){
    if(arr1[i]<=arr2[j]){
        if(uni.size()==0 || uni.back()!= arr1[i])
        uni.push_back(arr1[i]);
         i++; 
    }
    else{
        if(uni.size() ==0 || uni.back()!= arr2[j])
        uni.push_back(arr2[j]);
        j++;
    }
    }
    while(i<arr1.size()){
        if(uni.size()==0 || uni.back()!= arr1[i])
        uni.push_back(arr1[i]);
         i++;
    }
    while(j<arr2.size()){
         if(uni.size() ==0 || uni.back()!= arr2[j])
        uni.push_back(arr2[j]);
        j++;
    }
    return uni;

}
int main(){
    int n1, n2;
    cin>>n1;
    vector<int> arr1(n1);
    for(int i = 0; i<n1; i++){
        cin>>arr1[i];
    }
    cin>>n2;
    vector<int> arr2(n2);
    for(int i = 0; i<n2; i++)
    cin>>arr2[i];
vector<int> result = findunion(arr1, arr2);
for( int x: result )
cout<<x<<" ";
return 0;
}
//tc= 0(n1+n2) , sc= 0(n1+n2) optimal solution
