/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        Node* n = new Node(node->val);
        unordered_map<Node*,int> visit;
        unordered_map<Node*,Node*> oldnew;
        oldnew[node] = n;
        if(node->neighbors.empty())
            return n;
        queue<Node*> st;
        st.push(node);
        while(!st.empty())
        {
            auto t = st.front();
            for(auto nbr:t->neighbors)
            {
                if(oldnew.find(nbr)==oldnew.end())
                {
                    Node* nn = new Node(nbr->val);
                    oldnew[nbr] = nn;
                }
                // cout<<t->val<<" "<<nbr->val<<" "<<visit[nbr]<<endl;
                oldnew[t]->neighbors.push_back(oldnew[nbr]);
                if(!visit[nbr])
                {
                    st.push(nbr);
                    visit[nbr]=1;
                }
                
            }
            visit[t]=1;
            st.pop();
        }
        return n;
    }
};