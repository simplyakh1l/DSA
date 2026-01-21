class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        int n=s1.size();
        sort(s2.begin(),s2.end());
        int i=0;
        int f1=1,f2=1;
        for(int i=0;i<n;i++){
            if(s1[i]>=s2[i])continue;
            else f1=0;
        }
        for(int i=0;i<n;i++){
            if(s2[i]>=s1[i])continue;
            else f2=0;
        }

        if(f1 || f2)return true;
        return false;
    }
};