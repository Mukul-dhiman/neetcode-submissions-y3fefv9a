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
public:
    ListNode* add(ListNode* r1, ListNode* r2, int carry){
        int sum =  carry;
        if(r1){
            sum+=r1->val;
        }
        if(r2){
            sum+=r2->val;
        }
        int forward = sum/10;
        sum = sum%10;
        ListNode* node = new ListNode(sum);
        ListNode* next;
        if(r1 && r2){
            next = add(r1->next, r2->next, forward);
        }
        else if(r1 && !r2){
            next = add(r1->next, NULL, forward);
        }
        else if(!r1 && r2){
            next = add(NULL, r2->next, forward);
        }
        else if(carry==1){
            next = add(NULL, NULL, forward);
        }
        else{
            return NULL;
        }
        node->next = next;
        return node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ad = add(l1,l2,0);
        return ad;
    }
};
