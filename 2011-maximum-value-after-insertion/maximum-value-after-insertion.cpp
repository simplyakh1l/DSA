class Solution {
public:
    string maxValue(string s, int x) {
        int n=s.size();
        int f=(s[0]=='-')?0:1;
        string ans="";

        if(f==1){
            for(int i=0;i<n;i++){
                if(x>(s[i]-'0') && f==1){
                    ans+=(x+'0');
                    f=0;
                }
                ans+=s[i];
            }
            if(f==1)ans+=('0'+x);
        }
        else{
            for(int i=1;i<n;i++){
                if(x<(s[i]-'0') && f==0){
                    ans+=(x+'0');
                    f=1;
                }
                ans+=s[i];
            }
            if(f==0){
                ans+=('0'+x);
            }
            ans="-"+ans;
        }
        return ans;
        
    }
};