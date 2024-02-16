class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size();
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i =0; i<n; i++){
            int j = 1;
            while(i+1<n && a[i]==a[i+1]){
                j++;
                i++;
            }
            pq.push(j);
        }
        
        while(k>=pq.top()){
            int top = pq.top();
            pq.pop();
            k-=top;
        }
        return pq.size();
    }
};