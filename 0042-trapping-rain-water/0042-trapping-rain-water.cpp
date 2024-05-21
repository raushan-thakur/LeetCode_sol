class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>lm(n,0);
        vector<int>rm(n,0);
        int left = 0;
        int right = 0;
        for(int i =0; i< n; i++){
            if(height[i] > left) left = height[i];
            lm[i] = left;
        }
        
        for(int i =n-1; i>=0; i--){
            if(height[i] > right) right = height[i];
                rm[i] = right;
        }
        int ans = 0;
        for(int i=0; i<n ;i++) ans+=min(lm[i], rm[i])-height[i];
        return ans;
    }
};