class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        int m = nums2.size();
        vector<int> ans;
        vector<int> vis(1001,0);
        for(int i=0; i<n;i++){
            if(!vis[nums1[i]]){
                vis[nums1[i]]++;
                for(int j=0; j<m;j++){
                    if(nums1[i] == nums2[j]){
                        ans.push_back(nums1[i]);
                        break;
                    }
                }
            }
        }
        return ans;
        
    }
};