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
    unordered_map<int, Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr){return nullptr;}
        Node* temp = new Node(node->val);
        mp[node->val] = temp;

        for(auto n:node->neighbors){
            if(mp.find(n->val)==mp.end()){
                mp[n->val] = cloneGraph(n);
            }
            temp->neighbors.push_back(mp[n->val]);
        }
        
        return temp;
    }
};
