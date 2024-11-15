class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int right;
        
        for(right = n-1 ; right>=1 ; right--)
            if(arr[right-1] > arr[right])
                break;
        
        int ans = right;
        
        for(int i=0 ; i<n-1 && i<right ; i++){
            if(right == n || arr[i] <= arr[right]){
                ans = min(ans , right - i - 1);
            }else
                right++;
            
            if(arr[i] > arr[i+1]) break;
        }
        
        return ans;
    }
};