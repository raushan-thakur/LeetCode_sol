class Solution {
public:
    static bool mycmp(string a,string b){
        string total1 = a + b;
        string total2 = b + a;
        return total1 > total2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(auto i:nums){
            v.push_back(to_string(i));
        }
        sort(v.begin(),v.end(),mycmp);

        if(v[0] == "0"){
            return "0";
        }

        string ans = "";
        for(auto str:v){
            ans = ans + str;
        }
        return ans;
    }
};