class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> a(101,0);
        for(int i =0; i<n; i++){
            a[nums[i]]++;
        }
        sort(a.begin(), a.end());
        
        int ans = a[100];
        int x = a[100];
        int i = 99;
        while(a[i] == x){
            i--;
            ans+=a[100];
        }
        return ans;
    }
};