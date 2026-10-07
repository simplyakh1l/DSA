class Solution {
public:
    void sol(string &s, int n, vector<string>&ans){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        char tmp[]={'a','b','c'};

        for(auto it:tmp){
            if(s.empty() || s.back()!=it){
                s.push_back(it);
                sol(s,n,ans);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string>x;
        string s="";
        sol(s,n,x);


        if(k>x.size())return "";
        return x[k-1];
        
    }
};