class Solution {
public:
    int minimumSize(vector<int>& arr, int mx) {
        int l=1,r=*max_element(arr.begin(),arr.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            int ans=0;
            for(int i=0;i<arr.size();i++){
                if(arr[i]>=mid){
                    ans+=(arr[i]-1)/mid;
                }
            }
            if(ans>mx){
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }
        return r+1;
    }
};