class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        for(auto it: arr) mp[it]++;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 0 && mp[0] >1) return true;
            else if(mp[arr[i]*2] && arr[i] !=0) return true;
        }
        return false;
    }
};