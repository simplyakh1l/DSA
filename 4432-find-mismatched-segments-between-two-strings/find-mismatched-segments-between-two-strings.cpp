class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string> >ans;
        int n=s1.size();
        int i=0,j;
        while(i<n){
            if(s1[i]==s2[i]){
                i++;
                continue;
            }
            int j=i;
            string t1="",t2="";
            while(j<n && s1[j]!=s2[j]){
                t1+=s1[j]; t2+=s2[j];
                j++;
            }
            ans.push_back({t1,t2});
            i=j;
        }
        return ans;
        
    }
};