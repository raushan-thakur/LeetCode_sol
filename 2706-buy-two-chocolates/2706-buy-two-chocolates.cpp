class Solution {
public:
    int buyChoco(vector<int>& pr, int money) {
//         sort(pr.begin(), pr.end());
        
//         if(pr[0]+pr[1] <= money)
//             return money - pr[0]-pr[1];
        
//         return money;
        
        int firstMinCost = INT_MAX;
        int secondMinCost = INT_MAX;

        for (int p : pr) {
            if (p < firstMinCost) {
                secondMinCost = firstMinCost;
                firstMinCost = p;
            } else {
                secondMinCost = min(secondMinCost, p);
            }
        }

        int ans = money - (firstMinCost + secondMinCost);

        return ans >= 0 ? ans : money;
    }
};