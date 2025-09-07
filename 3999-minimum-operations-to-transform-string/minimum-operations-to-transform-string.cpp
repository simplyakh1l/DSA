class Solution {
public:
    int minOperations(string s) {
        
        int cnt=0;
        for(char c='b';c<='z';c++){
            int f=0;
            
            for(int i=0;i<s.size();i++){
                if(s[i]==c){
                    f=1;
                    if(s[i]=='z')s[i]='a';
                    else s[i]=(s[i]+1);
                }
            }
            if(f)cnt++;
        }
        return cnt;
    
        
    }
};