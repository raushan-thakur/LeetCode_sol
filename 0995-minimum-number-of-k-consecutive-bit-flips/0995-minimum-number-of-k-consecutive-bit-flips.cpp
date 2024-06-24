class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
         int n=nums.size();
        int ans=0;
        vector<int>v;
        for(int i=0;i<n;i++){
            int flip=0;
            int m=v.size();
            if(v.size()>0){
                flip=m;
            }
            int afterflip=0;
            if(flip%2==0){
                nums[i]=nums[i];
            }
            else{
                if(nums[i]==0)nums[i]=1;
                else nums[i]=0;
            }
            if(nums[i]==0){ 
                if((i+k-1)<n && (i+k-1)!=i )v.push_back(i+(k-1));
                else if((i+k-1)>=n) return -1;
                ans++;
            }
            if(m>0 && i==v[0]){
                v.erase(v.begin()+0); 
            }
        }
        return ans;
    }
};
