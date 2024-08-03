class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int count = 0;
        bool check = false;
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());

        for(int i = 0 ; i < target.size() ; i++){
                if( target[i] == arr[i] ){
                      count ++;
                }
        }
        if(count == target.size()){
            check = true;
        }
        return check;
    }
};