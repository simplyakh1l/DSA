/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> >ans;
        if(root==NULL)return ans;
        queue<Node*>q;
        q.push(root);

        while(q.size()){
            int n=q.size();
            
            vector<int>tmp;
            while(n--){
                Node* nde=q.front();
                q.pop();

                for(auto it:nde->children)q.push(it);

                tmp.push_back(nde->val);

            }
            ans.push_back(tmp);
        }
        return ans;
        
    }
};