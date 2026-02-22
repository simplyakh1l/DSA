class Solution {
public:
    string maximumXor(string s, string t) {
        int n=s.size();
        int vcnt=0;
        for(int i=0;i<n;i++){
            if(t[i]=='1')vcnt++;
            t[i]='0';
        }
        for(int i=0;i<n;i++){
            if(s[i]=='0' && vcnt){
                t[i]='1';
                vcnt--;
            }
            if(vcnt==0)break;
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1' && vcnt){
                t[i]='1';
                vcnt--;
            }
            if(vcnt==0)break;
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]==t[i]){
                ans+="0";
            }
            else ans+="1";
        }
        return ans;
        
    }
};