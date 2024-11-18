class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        
        if (k == 0) {
            return ans;
        } else if (k > 0) {
            
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = i + 1; j <= i + k; j++) {
                    int d = j % n;  
                    sum += code[d];
                }
                ans[i] = sum;
            }
        } else {
             
            k = abs(k);
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = i - 1; j >= i - k; j--) {
                    int d = (j % n + n) % n;  
                   
                    sum += code[d];
                }
                ans[i] = sum;
                 
            }
        }
        return ans;
    }
};
