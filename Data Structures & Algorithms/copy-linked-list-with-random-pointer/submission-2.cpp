/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*, Node*> mp;
        
        while(temp){
            Node* copy = new Node(temp->val);
            mp[temp] = copy;
            temp = temp->next;
        }
        cout<<endl;
        temp = head;
        while(temp){
            if(temp->next)
                mp[temp]->next = mp[temp->next];
            if(temp->random){
                mp[temp]->random = mp[temp->random]; 
            }
            temp=temp->next;
        }
        return mp[head];
    }
};
