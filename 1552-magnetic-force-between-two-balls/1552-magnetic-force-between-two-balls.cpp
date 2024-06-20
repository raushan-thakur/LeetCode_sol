class Solution {
public:
    bool isPossible(vector<int>& p, int m, int d){
        int cnt=1;
        int prev = 0;
        for(int i=1; i<p.size(); i++){
           if(p[i] - p[prev] >= d){
               prev=i;
               cnt++;
           } 
        }
        return cnt>=m;
    }
    int maxDistance(vector<int>& p, int m) {
        int ans = 0, n=p.size();
        sort(p.begin(), p.end());
        int h = p[n-1], l=1;
        
        while(l<=h){
            int mid = l + (h-l)/2;
            
            if(isPossible(p, m, mid)){
                ans = mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};