class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        double sum=0, result=INT_MAX;
        vector<pair<double,int>> d;
        
        for(int i=0;i<n;i++){
            d.push_back({wage[i]/(double)quality[i],quality[i]});
        }
        sort(d.begin(), d.end());
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(d[i].second);
            sum+=d[i].second;
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                result=min(result,sum*d[i].first);
            }
        }
    return result;
    }
};