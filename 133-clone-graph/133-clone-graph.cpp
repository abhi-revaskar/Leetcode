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
        unordered_map<Node*,Node*> oldnew;
        Node *ans;
        unordered_set<int> set;
        if(!node)
            return NULL;
        queue<Node*> q;
        ans = new Node(node->val);
        q.push(node);
        oldnew[node] = ans;
        set.insert(node->val);
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            for(auto x:top->neighbors)
            {
                Node *nbr;
                if(oldnew.count(x))
                    nbr = oldnew[x];
                else
                {
                    nbr = new Node(x->val);
                    oldnew[x] = nbr;
                }
                oldnew[top]->neighbors.push_back(nbr);
                if(set.count(x->val)==0)
                {
                    set.insert(x->val);
                q.push(x);
                }
            }
        }
        return ans;
    }
};