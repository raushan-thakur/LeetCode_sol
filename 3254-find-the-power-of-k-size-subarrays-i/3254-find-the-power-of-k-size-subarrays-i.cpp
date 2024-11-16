class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int l=0, r=k-1, n = nums.size();
        if( n==1) return {nums[0]};
        if(k==1) return nums;
        vector<int> ans;
        
        while(r<n){
            bool flag = true;
            for(int i=l; i<r; i++){
                if(nums[i+1] != nums[i]+1) flag =false;
            }
            if(flag && nums[r] == nums[r-1]+1) {
                ans.push_back(nums[r]);
            }
            else ans.push_back(-1);
            
            r++;
            l++;
        }
        return ans;
    }
};