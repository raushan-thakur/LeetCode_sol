class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<vector<int>>ans;
        for(int i = 1; i<n-1; i=i+3){
            if(nums[i+1]-nums[i-1]>k){
                return ans;
            }            
        }
        
        for(int i = 0; i<n; ){
            vector<int>a(3,0);
            for(int j = 0; j<3; j++){
                a[j]=nums[i++];
            }
            ans.push_back(a);
        }
        return ans;
    }
};