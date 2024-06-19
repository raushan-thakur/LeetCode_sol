class Solution {
public:
    bool isPossible(vector<int>& b, int m, int k, int mid){
        int total =0;
        int cnt=0;
        for(int i=0; i<b.size(); i++){
            if(b[i]<=mid) cnt++;
            else cnt=0;
            
            if(cnt == k){
                total++;
                cnt=0;
                
            }
        }
        
        return total >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long)m*k > n) return -1;
        int maxi = 0;
        
        for(auto it: bloomDay){
            if(it>maxi) maxi = it;
        }
        int l=1, h=maxi;
        int ans = 0;
        while(l<=h){
            int mid = l + (h-l)/2;
            
            if(isPossible(bloomDay, m, k, mid)){
                ans=mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};