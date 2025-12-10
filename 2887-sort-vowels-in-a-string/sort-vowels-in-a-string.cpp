class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        unordered_set<int>st;
        unordered_set<char>ch;
        ch.insert('A');
        ch.insert('E');
        ch.insert('I');
        ch.insert('O');
        ch.insert('U');
        ch.insert('a');
        ch.insert('e');
        ch.insert('i');
        ch.insert('o');
        ch.insert('u');

        string tmp="";
        for(int i=0;i<n;i++){
            if(ch.find(s[i])!=ch.end()){
                st.insert(i);
                tmp.push_back(s[i]);
            }
        }
        sort(tmp.begin(),tmp.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(st.find(i)!=st.end()){
                s[i]=tmp[j];
                j++;
            }
        }
        return s;
        
    }
};