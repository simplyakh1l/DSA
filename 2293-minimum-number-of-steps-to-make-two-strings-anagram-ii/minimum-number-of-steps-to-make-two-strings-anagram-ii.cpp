class Solution {
public:
    int sol(string s,string t){
        map<char,int>mpp;
        for(auto it:s)mpp[it]++;
        int cnt=0;
        for(auto it:t){
            if(mpp.find(it)==mpp.end() || mpp[it]<=0)cnt++;
            else mpp[it]--;
        }
        return cnt;
    }
    int minSteps(string s, string t) {
        int s1=sol(s,t),s2=sol(t,s);
        return s1+s2;

        
    }
};