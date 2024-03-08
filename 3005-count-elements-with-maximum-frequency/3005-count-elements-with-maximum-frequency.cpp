class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> a(101,0);
        for(int i =0; i<n; i++){
            a[nums[i]]++;
        }
        int maxi = 0;
        
        for(int i =1; i<101; i++){
            maxi = max(maxi, a[i]);
        }
        
        int ans = 0;
        for(int i =1; i<101; i++){
            if(a[i] == maxi) ans++;
        }

        return ans*maxi;
    }
};