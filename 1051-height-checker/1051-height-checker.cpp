class Solution {
public:
    void merge(vector<int>& h, int s, int m, int e){
        vector<int> temp;
        int l=s, r=m+1;
        while(l<=m && r<=e){
            if(h[l]<=h[r]){
                temp.push_back(h[l]);
                l++;
            }else{
                temp.push_back(h[r]);
                r++;
            }
        }
        while(l<=m){
            temp.push_back(h[l]);
            l++;
        }
        while(r<=e){
            temp.push_back(h[r]);
            r++;
        }
        
        for(int i=s; i<=e; i++){
            h[i] = temp[i-s];
        }
    }
    void mergesort(vector<int>& h, int s, int e){
        if(s>=e) return;
        
        int m = s + (e-s)/2;
        mergesort(h, s, m);
        mergesort(h, m+1, e);
        merge(h, s, m, e);
    }
    int heightChecker(vector<int>& heights) {
        vector<int>c = heights;
        mergesort(heights, 0, heights.size()-1);
        
        int cnt =0;
        for(int i=0; i<heights.size(); i++){
            if(heights[i] != c[i])cnt++;
        }
        return cnt;
    }
};