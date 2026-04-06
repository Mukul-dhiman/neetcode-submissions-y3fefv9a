/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    ListNode* reverseList(ListNode* head) {
        ListNode *prev, *curr, *next;
        curr = head;
        prev = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int sizeofLL(ListNode* head){
        if(!head)   return 0;
        return 1+sizeofLL(head->next);
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(sizeofLL(head)<k){
            return head;
        }
        int temp = k-1;
        ListNode* kth = head;
        ListNode* nextgroup = head;
        
        while(temp--){
            kth = kth->next;
        }
        nextgroup = kth->next;
        kth->next = NULL;
        head = reverseList(head);
        nextgroup = reverseKGroup(nextgroup, k);
        kth = head;
        while(kth->next){
            kth = kth->next;
        }
        kth->next = nextgroup;
        return head;
    }
};
