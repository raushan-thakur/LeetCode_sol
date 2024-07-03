class Solution {
public:
    int solve(vector<int> arr,int i,int j,int k){
      if(k==3) return arr[j]-arr[i];
      return min(solve(arr,i+1,j,k+1),solve(arr,i,j-1,k+1));
    }
    int minDifference(vector<int>& arr) {
        if(arr.size()<=4) return 0;
        sort(arr.begin(),arr.end());
        return solve(arr,0,arr.size()-1,0);
    }
};