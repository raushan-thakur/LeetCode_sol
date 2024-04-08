class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sw) {
        int n = st.size();
        int zc =0;
        for(int i = 0; i<n; i++) if(st[i] == 0) zc++;
        int oc = n - zc;
        
        for(int i= 0; i<n; i++){
            if(sw[i] == 0 && zc == 0) return oc;
            if(sw[i] == 1 && oc == 0) return zc;
            
            if(sw[i] == 0) zc--;
            else oc--;
        }
        return 0;
    }
};