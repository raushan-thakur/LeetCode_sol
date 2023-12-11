class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        for(int i = 1 ;i<n; i++){
            int countofeach = 1;
            while(i<n && arr[i] == arr[i-1] ){
                countofeach++;
                if(countofeach>(n/4))
                    return arr[i];

                i++;
            }
        }
        return arr[0];
    }
};