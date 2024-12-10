class Solution {
public:
    bool check(string s , int len){
        unordered_map<char,int> mp;
        for(int i = 0 ; i < s.size() - len + 1 ; i ++){
            set<char> st;
            for(int j = i ; j < i+len ; j++){
                st.insert(s[j]);
            }
            if(st.size()==1)mp[s[i]]++;
        }
        for(auto it : mp){
            if(it.second>=3)return true;
        }
        return false;
    }

    int maximumLength(string s) {
        int ans = 0;
        int low = 1 , high = s.size();
        while(low<=high){
            int mid = (high + low)/2;
            if(check(s,mid)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high==0?-1:high;
    }
};