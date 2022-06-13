/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> st;
        if(!root)
            return s;
        st.push(root);
        while(!st.empty())
        {
            auto t = st.front();
            if(!t)
                s+="N " ;
            else
            {
                s+=to_string(t->val)+' ';
                st.push(t->left);
                st.push(t->right);
            }
            st.pop();
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return NULL;
        int i=0;
        vector<string> v;
        string temp="";
        for(int i=0;i<data.length();i++)
        {
            if(data[i]!=' ')
            {
                temp+=data[i];
            }
            else
            {
                v.push_back(temp);
                temp="";
            }
        }
        queue<TreeNode*> q;
        TreeNode* node  = new TreeNode(stoi(v[i]));
        q.push(node);
        i++;
        while(!q.empty() && i<v.size())
        {
            auto t = q.front();
            if(t)
            {
                if(v[i]!="N")
                {
                    TreeNode* node1  = new TreeNode(stoi(v[i]));
                    t->left = node1;
                    q.push(node1);
                }
                i++;
                if(v[i]!="N")
                {
                    TreeNode* node2  = new TreeNode(stoi(v[i]));
                    t->right = node2;
                    q.push(node2);
                }
                i++;
                q.pop();
            }
            
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));