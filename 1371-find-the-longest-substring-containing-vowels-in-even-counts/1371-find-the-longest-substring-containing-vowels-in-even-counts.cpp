class Solution{
public:
    int findTheLongestSubstring(string s){
      unordered_map<int,int> mp;
        int ans=0;
        int mask=0;
        mp[0]=-1;
        vector<int> v(27,0);
        v['a'-97]=0;v['e'-97]=1;v['i'-97]=2;v['o'-97]=3;v['u'-97]=4;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                int pos=v[s[i]-97];
                
                if(mask && (1<<pos))
                    mask=(mask^(1<<pos));
                else
                    mask=(mask|(1<<pos));
            }
            
            if(mp.count(mask))
              ans=max(ans,i-mp[mask]);  
            else
                mp[mask]=i;
        }
        return ans;
    }
};