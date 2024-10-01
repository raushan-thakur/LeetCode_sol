class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> c;
        
        for (const auto& num : arr) {
            c[(num % k + k) % k]++; 
        }
        
        for (int i = 1; i < k - i; i++) {
            if ((c[i] != c[k - i])) return false;
        }
        
        if (k % 2 == 0 && (c[k / 2] % 2)) return false;
        
        return true;
    }
};