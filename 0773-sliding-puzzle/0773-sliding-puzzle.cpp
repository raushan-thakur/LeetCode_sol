class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string end = "123450";
        string start = "";
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                start+=to_string(board[i][j]);
            }
        }
        vector<vector<int>> pos = {{1,3}, {0,4,2},{1,5},{0,4},{3,1,5},{2,4}};
        
        set<string> st;
        st.insert(start);
        queue<pair<string, int>> q;
        q.push({start,0});
        
        while(!q.empty()){
            auto first = q.front();
            q.pop();
            string curr = first.first;
            int move = first.second;
            
            int idx = curr.find('0');
            if(end == curr) return move;
            
            for(auto it:pos[idx]){
                string newc = curr;
                swap(newc[idx], newc[it]);
                if(!st.count(newc)){
                    st.insert(newc);
                    q.push({newc,move+1});
                }
            }
            
        }
        return -1;
    }
};