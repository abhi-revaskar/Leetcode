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
        unordered_map<Node*,Node*> oldnew;
        Node *ans = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        oldnew[node] = ans;
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            for(auto x:top->neighbors)
            {
                if(oldnew.count(x)==0)
                {
                    oldnew[x] = new Node(x->val);
                    q.push(x);
                }
                oldnew[top]->neighbors.push_back(oldnew[x]);
            }
        }
        return ans;
    }
};