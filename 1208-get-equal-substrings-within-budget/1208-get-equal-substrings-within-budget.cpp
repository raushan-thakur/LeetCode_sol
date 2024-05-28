class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0,i=0,j=0,cnt=0,n=s.size();
        while(j<n){
            cnt+=abs(s[j]-t[j]);
            while(cnt>maxCost && i<=j){
                cnt-=abs(s[i]-t[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};