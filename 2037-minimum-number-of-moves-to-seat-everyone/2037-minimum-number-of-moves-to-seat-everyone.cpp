class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& s) {
        int ans =0;
        sort(seats.begin(), seats.end());
        sort(s.begin(), s.end());
        
        for(int i=0; i<seats.size(); i++){
            ans+=abs(seats[i] - s[i]);
        }
        return ans;
    }
};