class Solution {
public:
    int findKthNumber(int n, int k) {
        int currentNumber = 1;  
        k--;  
        while (k > 0) {
            long long steps = countSteps(n, currentNumber, currentNumber + 1);
            
            if (steps <= k) {
                currentNumber += 1;
                k -= steps;
            } else {
                currentNumber *= 10;
                k--;
            }
        }
        
        return currentNumber;
    }
    

    long long countSteps(int n, long long curr, long long next) {
        long long steps = 0;
        
        while (curr <= n) {
            steps += min((long long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        
        return steps;
    }
};