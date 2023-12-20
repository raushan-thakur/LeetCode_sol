class Solution {
public:
    int buyChoco(vector<int>& p, int money) {
        sort(p.begin(), p.end());
        
        if(p[0]+p[1] <= money)
            return money - p[0]-p[1];
        
        return money;
    }
};