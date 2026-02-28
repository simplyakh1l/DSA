class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        int n=s.size();
        int j=n-1;
        while(j>0){
            if(s[j]=='0'){
                j--;
                ans++;
            }
            else{
                int i=j;
                while(i>=0 && s[i]=='1'){
                    s[i]='0';
                    i--;
                }
                if(i==-1){
                    s="1"+s;
                    j++;
                }
                else s[i]='1';
                ans++;
               
           
            }
        }
        return ans;
    }
};