class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>mpp(26);
        int n=s.size();

        for(int i=0;i<n;i++){
            mpp[s[i]-'a']++;
            mpp[t[i]-'a']--;
        }

        //-ve value: extra char
        //+v val: def char

        int cnt=0;
        for(auto it:mpp)cnt+=abs(it);

        return cnt/2;
        
    }
};