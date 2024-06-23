class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        priority_queue<pair<int,int>>maxpq;

        int start = 0,ans=1;
        for(int i=0;i<n;i++){
            while(!pq.empty() && abs(nums[i]-pq.top().first)>limit){
                start = max(start,pq.top().second+1);
                pq.pop();
            }
            while(!maxpq.empty() && abs(nums[i]-maxpq.top().first)>limit){
                start = max(start,maxpq.top().second+1);
                maxpq.pop();
            }
            //cout<<start<<" "<<i<<endl;
            ans=max(ans,i-start+1);
            pq.push({nums[i],i});
            maxpq.push({nums[i],i});
        }

        return ans;
    }
};